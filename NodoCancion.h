#include <iostream>
#include <string>

using namespace std;

struct NodoCancion
{
    NodoCancion *siguiente;
    Cancion *cancion;
    int id;

    // Constructor
    NodoCancion(Cancion *cancion, int id)
    {
        this->siguiente = NULL;
        this->cancion = cancion;
        this->id = id;
    }
};
