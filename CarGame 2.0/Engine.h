#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include<iostream>
#include <string>
#include<vector>
#include "Object.h"
#include"Texture.h"
#include"Dot.h"

using namespace std;



#define LEVEL_WIDTH  1000
#define LEVEL_HEIGHT 3918
#define SCREEN_WIDTH  1000
#define SCREEN_HEIGHT  700

void resetare();

class var
{
public:
	//The window we'll be rendering to
	static SDL_Window* gWindow ;

	//The window renderer
	static SDL_Renderer* gRenderer ;

	static vector <LTexture*> Stelute;
	static LTexture* gDotTexture;
	static LTexture* gBGTexture;

	static LTexture* win;

	static bool reset ;
	static int nrStele;



	
};



