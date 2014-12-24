#ifndef GLOBALS_HPP
	#define GLOBALS_HPP
#include <SDL.h>
#include <SDL_ttf.h>
#include "texture.hpp"

class LTexture;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

//The dimensions of the level
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILES = 192;
const int TOTAL_TILE_SPRITES = 12;

//The different tile sprites
const int TILE_RED = 0;
const int TILE_GREEN = 1;
const int TILE_BLUE = 2;
const int TILE_CENTER = 3;
const int TILE_TOP = 4;
const int TILE_TOPRIGHT = 5;
const int TILE_RIGHT = 6;
const int TILE_BOTTOMRIGHT = 7;
const int TILE_BOTTOM = 8;
const int TILE_BOTTOMLEFT = 9;
const int TILE_LEFT = 10;
const int TILE_TOPLEFT = 11;

//The window we'll be rendering to
extern SDL_Window *gWindow;

//The window renderer
extern SDL_Renderer *gRenderer;

// Font.
extern TTF_Font *gFont;

extern bool checkCollision(SDL_Rect a, SDL_Rect b);
extern LTexture gTileTexture;
extern SDL_Rect gTileClips[TOTAL_TILE_SPRITES];
#endif