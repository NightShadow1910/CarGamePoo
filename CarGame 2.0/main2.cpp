#include"Engine.h"

SDL_Renderer*  var:: gRenderer = NULL;
SDL_Window* var:: gWindow = NULL;
vector<LTexture*>var::Stelute;
LTexture* var::gDotTexture=NULL;
LTexture* var::gBGTexture=NULL;
int var::nrStele = 0;
LTexture* var::win = nullptr;


//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();


struct Coord
{
	int x;
	int y;
	bool luat = false;

};
vector<Coord>CoordSteluta;


int main( int argc, char* args[] )
{

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 framesStart;
	int frameTime;


	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
			
			var::gDotTexture = loadMedia("Assets/Player Cars/GreenStrip.png");
			var::gBGTexture = loadMedia("Assets/HUD/Map/Road2.0.png");
			//LTexture* ceva = loadMedia("Assets/Star_03.png", 1);
			
			for(int i=0; i<7;i++)
				var::Stelute.push_back(loadMedia("Assets/Star_03.png"));
			
			CoordSteluta.push_back({ 440, 300 });
			CoordSteluta.push_back({ 55, 800 });
			CoordSteluta.push_back({ 825, 1700 });
			CoordSteluta.push_back({ 635, 2000 });
			CoordSteluta.push_back({ 250, 2500 });
			CoordSteluta.push_back({ 440, 2900 });
			CoordSteluta.push_back({ 55, 3200 });
			
			
			//The dot that will be moving around on the screen
			Dot dot;

			//The camera area
			SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };


			//While application is running
			while( !quit )
			{
				framesStart = SDL_GetTicks();
				frameTime = SDL_GetTicks() - framesStart;
				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}

				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
						
					}
					//cout << camera.x << " " << camera.y << endl;
					//Handle input for the dot
					dot.handleEvent( e );
				}


				//Move the dot
				dot.move();

				//Center the camera over the dot
				camera.x = (dot.getPosX() + dot.Obj_width / 2) - SCREEN_WIDTH / 2;
				camera.y = (dot.getPosY() + dot.Obj_height / 2) - SCREEN_HEIGHT / 2;

				//Keep the camera in bounds
				if (camera.x < 0)
				{
					camera.x = 0;
				}
				if (camera.y < 0)
				{
					camera.y = 0;
				}
				if (camera.x > LEVEL_WIDTH - camera.w)
				{
					camera.x = LEVEL_WIDTH - camera.w;
				}
				if (camera.y > LEVEL_HEIGHT - camera.h)
				{
					camera.y = LEVEL_HEIGHT - camera.h;
				}

				
				
				//Clear screen
				SDL_SetRenderDrawColor(var::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(var::gRenderer);

				//Render background
				var::gBGTexture->render(0, 0, &camera);

				//Render objects
				dot.render(camera.x, camera.y);
				
				for (int i = 0; i < 7; ++i)
				{
					var::Stelute.at(i)->render(CoordSteluta.at(i).x, CoordSteluta.at(i).y - camera.y);
					if (((dot.Obj_x<= CoordSteluta.at(i).x +150 && (dot.Obj_x+120) >= CoordSteluta.at(i).x+150 && 
						dot.Obj_y<= CoordSteluta.at(i).y+144 && dot.Obj_y>= CoordSteluta.at(i).y)  ||
						((dot.Obj_x + 120)>= CoordSteluta.at(i).x && dot.Obj_x <= CoordSteluta.at(i).x &&
						dot.Obj_y <= CoordSteluta.at(i).y + 144 && dot.Obj_y >= CoordSteluta.at(i).y))  &&
						CoordSteluta.at(i).luat == false)
					{
						CoordSteluta.at(i).luat = true;
						var::Stelute.at(i) = loadMedia("Assets/HUD/Map/Gol.png");
						cout << "sunt aici"<<i << endl;
						var::nrStele++;
						cout << var::nrStele << endl;
					}
				}

				if (dot.getPosY() <= 100)
				{
					
					if (var::nrStele == 7)
						var::win = loadMedia("Assets/PNG/You_Win/Header.png");
					else
					{
						var::win = loadMedia("Assets/PNG/You_Lose/Header.png");
						var::reset = 1;
					}
					var::win->render(300, 400);
				}
				

				//Update screen
				SDL_RenderPresent(var::gRenderer);
			}
		
	}

	//Free resources and close SDL
	close();

	return 0;}