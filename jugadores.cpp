#include <iostream>
#include <fstream>
#include "jugadores.h"

using namespace std;

Jugadores::Jugadores()
{

}
ostream &operator <<(ostream &os, Jugadores &obj)
{
    os << obj.getNombre()<<"|"<<obj.getPuntaje();
    return os;
}
istream &operator >>(istream &is, Jugadores &obj)
{
    string aux;
    getline(is, aux, '|');
    if (aux.size() >0)
    {
        obj.setNombre(aux);
        getline(is, aux, '|');
        obj.setPuntaje(stoi(aux));
    }
    return is;
}
string Jugadores::getNombre()
{
    return nombre;
}
void Jugadores::setNombre(string aux)
{
    nombre = aux;
}
int Jugadores::getPuntaje()
{
    return puntaje;
}
void Jugadores::setPuntaje(int aux)
{
    puntaje=aux;
}
