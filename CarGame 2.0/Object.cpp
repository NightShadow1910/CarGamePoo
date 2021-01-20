#include "Engine.h"

void Object::SetTexture(const LTexture* text)
{
	this->mTexture = text->mTexture;
	this->mHeight = text->getHeight();
	this->mWidth = text->getWidth();
}


void Object::render(int camX, int camY)
{
	//Show the dot relative to the camera
	var::gDotTexture->render(Obj_x - camX, Obj_y - camY);
}

void Object::SetTexture(SDL_Texture* text)
{
	mTexture = text;
}

