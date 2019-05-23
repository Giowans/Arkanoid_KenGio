#ifndef ARKANOIDGAME_H_
#define ARKANOIDGAME_H_
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>

#include "game.h"
#include "Board.h"
#include "Paddle.h"
#include "Ball.h"

#define FPS_DELAY 500

class ArkanoidGame: public Game 
{
    private:
        // Timing
        unsigned int lasttick, fpstick, fps, framecount;

        // Test
        float testx, testy;
        
        unsigned int score;
        Board* board;
        Paddle* paddle;
        Ball* ball;
        bool paddlestick;
    public:
        ArkanoidGame();
        //~ArkanoidGame();

        void clean();
        void run();
        void update(float delta);
        void render(float delta);
        void handleEvents();

        void NewGame();
        void ResetPaddle();
        void StickBall();

        void SetPaddleX(float x);
        void CheckBoardCollisions();
        float GetReflection(float hitx);
        void CheckPaddleCollisions();
        void CheckBrickCollisions();
        void CheckBrickCollisions2();
        void BallBrickResponse(int dirindex);
        int GetBrickCount();
};
#endif 