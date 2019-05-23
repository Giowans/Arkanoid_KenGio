#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <SDL.h>
#include<SDL_ttf.h>
#include <SDL_image.h>
#include "jugadores.h"
using namespace std;

class Game
{
private:
    Jugadores jugador;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int screenWidth;
    int screenHeight;

public:
    SDL_Color txtcolor, txtcolorbg;
    TTF_Font *font;
    SDL_Surface *surf;
    SDL_Texture *texture;
    char textito[80];//variable que nos permite renderizar los puntajes y el nombre
    Game();
    Jugadores getJugador();
    void setJugador(Jugadores aux);
    bool getIsRunning() const;
    void setIsRunning(bool value);
    SDL_Window *getWindow() const;
    void setWindow(SDL_Window *value);
    SDL_Renderer *getRenderer() const;
    void setRenderer(SDL_Renderer *value);
    int getScreenWidth() const;
    void setScreenWidth(int value);
    int getScreenHeight() const;
    void setScreenHeight(int value);
    //Funcion para leer y escribir los puntajes de los jugadores en archivos
    void leerJugadores();
    void escribirJugadores();
    //init("título", ancho, alto, ¿pantallaCompleta?)
    void init(const char *title, int w, int h, bool fullscreen);
    /*virtual void run() = 0;
    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void clean() = 0;*/
};

#endif // GAME_H
