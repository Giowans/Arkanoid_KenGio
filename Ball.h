// ------------------------------------------------------------
// The Breakout Tutorial
// (c) 2015 Rembound.com
// http://rembound.com/articles/the-breakout-tutorial
// ------------------------------------------------------------

#ifndef BALL_H_
#define BALL_H_
#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>
#include <math.h>

// Define a ball speed in pixels per second
const float BALL_SPEED = 550;

class Ball: public Entity {
public:
    Ball(SDL_Renderer* renderer);
    ~Ball();

    void Update(float delta);
    void Render(float delta);

    void SetDirection(float dirx, float diry);

    float dirx, diry;

private:
    SDL_Texture* texture;

};
#endif
