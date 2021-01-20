#include "Engine.h"

Dot::Dot()
{
    //Initialize the offsets
    Obj_x = 440;
    Obj_y = 3700;

    //Set collision box dimension


    //Initialize the velocity
    mVelX = 0;
    mVelY = -DOT_VEL;
}

void Dot::handleEvent(SDL_Event& e)
{

    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        //Adjust the velocity and reset
        switch (e.key.keysym.sym)
        {

        case SDLK_LEFT: mVelX -= DOT_VEL * 2; break;
        case SDLK_RIGHT: mVelX += DOT_VEL * 2; break;
        
        }
    }
    //If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {

        case SDLK_LEFT: mVelX += DOT_VEL * 2; break;
        case SDLK_RIGHT: mVelX -= DOT_VEL * 2; break;
        case SDLK_SPACE: if (var::reset == true) resetare(); break;
        
        }
    }
}

int Object::getPosX()
{
    return Obj_x;
}

int Object::getPosY()
{
    return Obj_y;
}

void Dot::move()
{
    //Move the dot left or right
    Obj_x += mVelX;
    //cout << Obj_y << endl;
    //If the dot went too far to the left or right
    if ((Obj_x < 0) || (Obj_x + 120 > LEVEL_WIDTH))
    {
        //Move back
        Obj_x -= mVelX;
    }

    //Move the dot up or down
    Obj_y += mVelY;

    //If the dot went too far up or down
    if ((Obj_y < 0) || (Obj_y + Obj_height > LEVEL_HEIGHT))
    {
        //Move back
        Obj_y -= mVelY;


    }
}