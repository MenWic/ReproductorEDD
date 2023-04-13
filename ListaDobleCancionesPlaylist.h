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
        cout << "Se elimino la cancion" << endl;
    }

    void imprimirCanciones()
    {
        NodoDobleCancion *actual = cabeza;
        cout << "\n\t \"Canciones en la Playlist\" " << endl
             << "Formato: Id. Nombre - Descripcion." << endl;

        while (actual != NULL)
        {
            cout << actual->id << ". " << actual->cancion->getNombre() << " - " << actual->cancion->getPath() << "." << endl;
            actual = actual->siguiente;
        }

        cout << "\n\tFin" << endl;
    }

    void reproducirNormal()
    {
        NodoDobleCancion *actual = cabeza;
        int reproducirDeNUevo = 0;

        while (actual != NULL)
        {
            cout << "Reproduciendo" << actual->id << ". " << actual->cancion->getNombre() << " - " << actual->cancion->getPath() << "." << endl;

            pause();
            cout << "1.Reproducir siguiente 2.Reproducir anterior" << endl;
            cin >> reproducirDeNUevo;

            //ARREGLAR A SWITCH
            if (reproducirDeNUevo == 1)
            {
                actual = actual->siguiente;
            }
            else
            {
                actual = actual->anterior;
            }
        }

        cout << endl;
    }

    void reproducirInfinita()
    {
        NodoDobleCancion *actual = cabeza;
        int reproducirDeNUevo = 0;
        while (actual != NULL)
        {
            cout << "Reproduciendo" << actual->id << ". " << actual->cancion->getNombre() << " - " << actual->cancion->getPath() << "." << endl;
            pause();

            cout << "1.Reproducir siguiente 2.Reproducir anterior" << endl;
            cin >> reproducirDeNUevo;
            if (reproducirDeNUevo == 1)
            {
                actual = actual->siguiente;
            }
            else
            {
                actual = actual->anterior;
            }

            if (actual == NULL)
            {
                cout << "La Play list acabo\n-1.Si Desea reproducir la play list nuevamente" << endl;
                cin >> reproducirDeNUevo;
                if (reproducirDeNUevo == -1)
                {
                    actual = cabeza;
                }
                else
                {
                    return;
                }
            }
        }
        cout << endl;
    }

    void pause()
{
	cout << "Pulsa una tecla para continuar...";
	getwchar();
	getwchar();
}
};