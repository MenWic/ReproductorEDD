#include <iostream>
#include <string>

using namespace std;

struct NodoDobleCancion
{
    NodoDobleCancion *anterior;
    NodoDobleCancion *siguiente;
    Cancion *cancion;
    int id;

    // Constructor
    NodoDobleCancion(Cancion *cancion, int id)
    {
        this->anterior = NULL;
        this->siguiente = NULL;
        this->cancion = cancion;
        this->id = id;
    }

    // Getters y Setters
};