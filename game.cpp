#include "game.h"
#include <fstream>
#include <iostream>
#include <SDL_ttf.h>
using namespace std;

bool Game::getIsRunning() const
{
    return isRunning;
}

void Game::setIsRunning(bool value)
{
    isRunning = value;
}

SDL_Window *Game::getWindow() const
{
    return window;
}

void Game::setWindow(SDL_Window *value)
{
    window = value;
}
SDL_Renderer *Game::getRenderer() const
{
    return renderer;
}
void Game::setRenderer(SDL_Renderer *value)
{
    renderer = value;
}
int Game::getScreenWidth() const
{
    return screenWidth;
}

void Game::setScreenWidth(int value)
{
    screenWidth = value;
}

int Game::getScreenHeight() const
{
    return screenHeight;
}

void Game::setScreenHeight(int value)
{
    screenHeight = value;
}

Game::Game()
{
    string gt;
    isRunning = false;
    cout<<"\t\t\t\tEL ARKANOID DEL GIO 7u7"<<endl;
    cout<<endl<<"Ingresa tu gamertag: ";
    fflush(stdin);
    getline(cin, gt);
    jugador.setNombre(gt);
    jugador.setPuntaje(0);
}

void Game::init(const char *title, int w, int h, bool fullscreen)
{
    int flags = 0;
    screenWidth = w;
    screenHeight = h;
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    //renderer
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        //SDL_CreateWindow(titulo, posX, posY, ancho, alto, banderas)
        TTF_Init();
        window = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  screenWidth,
                                  screenHeight,
                                  flags);
        font = TTF_OpenFont("comic.ttf", 14);
        txtcolor = {221, 247, 113};
        txtcolorbg={0, 0, 0};
        sprintf(textito, "Jugador: %s \nPuntaje: %i", jugador.getNombre().c_str(), jugador.getPuntaje());
        surf = TTF_RenderText_Shaded(font, textito, txtcolor, txtcolorbg);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            //SDL_SetRenderDrawColor(renderer, r, g, b, alpha)
            // r, g  y b son valores entre 0 y 255
            // 0, 0, 0 es color negro
            // 255, 255, 255, es color blanco
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            //Inicializamos el texto del renderizador de los records
            texture =SDL_CreateTextureFromSurface(renderer, surf);
            int texW = 0;
            int texH = 0;
            SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
            SDL_Rect dstrect = { 0, 0, texW, texH };
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);
            SDL_RenderPresent(renderer);
            
        }
        else
            cout <<"couldn't initialize renderer " <<SDL_GetError() <<endl;

        isRunning = true;
    }
}
void Game::escribirJugadores()
{
    ofstream outputFile("jugadores.txt", ios::app);
    if (!outputFile.is_open()) 
    {
        cout << "No se pudo abrir el archivo de escritura"<<endl;
    }
    else
    {
        outputFile<<jugador<<endl;
    }
    outputFile.close();    
}
void Game::leerJugadores()
{
    ifstream inputFile("jugadores.txt", ios::app);
    if (!inputFile.is_open()) 
    {
        cout<<"No se pudo abrir el archivo de lectura..."<<endl;
    }
    else
    {
        Jugadores j;
        while(inputFile >>j)
        {
           cout << j <<endl; 
        }
    }
    inputFile.close();
}
Jugadores Game::getJugador()
{
    return jugador;
}
void Game::setJugador(Jugadores aux)
{
    jugador = aux;
}