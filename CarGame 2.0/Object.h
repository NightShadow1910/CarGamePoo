#pragma once
#include "Engine.h"
#include "Texture.h"

class Object :public LTexture
{
public:
	Object(int x = 0, int y = 0, int h = 0, int w = 0)
	{
		Obj_height = h;
		Obj_width = w;
		Obj_x = x;
		Obj_y = y;
		mHeight = h;
		mWidth = w;
	}
	void SetTexture(SDL_Texture* text);
	void SetTexture(const LTexture* text);
	int Obj_height;
	int Obj_width;
	int Obj_x;
	int Obj_y;
	//Shows the dot on the screen relative to the camera
	void render(int camX, int camY);

	//Position accessors
	int getPosX();
	int getPosY();


};