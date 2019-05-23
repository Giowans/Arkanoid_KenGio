#include <iostream>
#include <fstream>

using namespace std;

class Jugadores
{
    private:
        string nombre;
        int puntaje;
    public:
        Jugadores();
        string getNombre();
        void setNombre(string aux);
        int getPuntaje();
        void setPuntaje(int aux);

        friend ostream &operator <<(ostream &os,  Jugadores &obj);
        friend istream &operator >>(istream &is,  Jugadores &obj);
};