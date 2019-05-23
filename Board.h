// ------------------------------------------------------------
// The Breakout Tutorial
// (c) 2015 Rembound.com
// http://rembound.com/articles/the-breakout-tutorial
// ------------------------------------------------------------
#ifndef BOARD_H_
#define BOARD_H_
#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;
// Define the dimensions of the board and bricks
#define BOARD_WIDTH 12
#define BOARD_HEIGHT 12
#define BOARD_BRWIDTH 64
#define BOARD_BRHEIGHT 24

class Brick {
public:
    int type;
    bool state;
};

class Board: public Entity {
public:
    Board(SDL_Renderer* renderer);
    ~Board();

    void Update(float delta);
    void Render(float delta);
    void CreateLevel();

    float brickoffsetx, brickoffsety;

    // Define the two-dimensional array of bricks
    Brick bricks[BOARD_WIDTH][BOARD_HEIGHT];

private:
    SDL_Texture* bricktexture;
    SDL_Texture* sidetexture;
};

#endif //BOARD_H_
