#include <iostream>
#include <string>

using namespace std;

struct ListaDobleCancionesPlaylist
{
    NodoDobleCancion *cabeza;
    NodoDobleCancion *cola;
    int size;

    // Constructor
    ListaDobleCancionesPlaylist()
    {
        cabeza = NULL;
        cola = NULL;
        size = 0;
    }

    /*  Metodos Principales de Lista Enlazada   */
    // Function: @agregarNodo(), Metodo para incersion de nodos a la Lista Enlazada
    void agregarCancion(Cancion *cancion)
    {
        NodoDobleCancion *nuevo_nodo = new NodoDobleCancion(cancion, this->size); // NodoCancion()
        nuevo_nodo->anterior = cola;

        if (cabeza != NULL)
        { // Cuando no hay ningun nodo creado aun..
            cola->siguiente = nuevo_nodo;
        }
        else
        {
            cabeza = nuevo_nodo;
        }
        cola = nuevo_nodo;
        cout << "Se agrego la cancion a la Playlist" << endl;
        size++;
    }

    void eliminarCancion(int index)
    {
        NodoDobleCancion *actual = cabeza;

        while (actual != NULL && actual->id != index)
        {
            actual = actual->siguiente;
        }

        if (actual == NULL)
        {
            return;
            cout << "No hay canciones en la lista" << endl;
        }

        if (actual->anterior != NULL)
        {
            actual->anterior->siguiente = actual->siguiente;
        }
        else
        {
            cabeza = actual->siguiente;
        }

        if (actual->siguiente != NULL)
        {
            actual->siguiente->anterior = actual->anterior;
        }
        else
        {
            cola = actual->anterior;
        }

        delete actual;
        cout << "Se elimino la cancion." << endl;
    }

    void imprimirCanciones()
    {
        NodoDobleCancion *actual = cabeza;
        cout << "\n\t Canciones en la Playlist " << endl
             << "Id. Nombre - Descrip." << endl;

        while (actual != NULL)
        {
            cout << actual->id << ". " << actual->cancion->getNombre() << " - " << actual->cancion->getPath() << "." << endl;
            actual = actual->siguiente;
        }

        cout << endl;
    }
};