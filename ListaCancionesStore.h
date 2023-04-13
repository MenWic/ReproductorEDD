#include <iostream>
#include <string>

using namespace std;

struct ListaCancionesStore
{
    NodoCancion *cabeza;
    int size;

    // Constructor
    ListaCancionesStore()
    {
        cabeza = NULL;
        size = 0;
    }

    /*****************************************
     * Metodos Principales de Lista Enlazada *
     ******************************************/
    // Function: @agregarNodo(), Metodo para incersion de nodos a la Lista Enlazada
    void agregarCancion(string nombre, string path)
    {
        NodoCancion *nuevo_nodo = new NodoCancion(new Cancion(nombre, path), this->size); // NodoCancion()

        if (cabeza == NULL)
        { // Cuando no hay ningun nodo creado aun...
            cabeza = nuevo_nodo;
        }
        else
        {
            NodoCancion *nodo_actual = cabeza;
            while (nodo_actual->siguiente != NULL)
            {                                         // Mientras el siguiente del nodo evaluado no sea null...
                nodo_actual = nodo_actual->siguiente; // Seguir moviendonos al siguiente hasta encontrar el NULL
            }
            nodo_actual->siguiente = nuevo_nodo; // Al haber encontrado el NULL, creamos o setteamos nuestro nodo a crear
        }
        cout << "\"Se agrego la cancion a la Store\"" << endl;
        size++;
    }

    // Function: @eliminarNodo(), Metodo para eliminacion de nodos de la Lista Enlazada
    void eliminarCancionPorNombre(string nombre)
    { // Param: atributo nombre del nodo que deseamos eliminar
        NodoCancion *nodo_actual = cabeza;
        NodoCancion *nodo_anterior = NULL;

        while (nodo_actual != NULL && nodo_actual->cancion->getNombre() != nombre)
        { // Mientras el nodo actual no sea NULL, el nombre no coincida...
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->siguiente;
        }

        if (nodo_actual != NULL)
        {
            if (nodo_anterior == NULL)
            {
                cabeza = nodo_actual->siguiente;
            }
            else
            {
                nodo_anterior->siguiente = nodo_actual->siguiente;
            }
            delete nodo_actual;
            cout << "Se elimino la cancion...";
        }
        else
        {
            cout << "No se enontro la cancion a eliminar...";
        }
    }

    // Function: @eliminarNodo(), Metodo para eliminacion de nodos de la Lista Enlazada
    void eliminarCancionPorIndex(int index)
    { // Param: atributo nombre del nodo que deseamos eliminar
        NodoCancion *nodo_actual = cabeza;
        NodoCancion *nodo_anterior = NULL;

        if (nodo_actual != NULL)
        {
            while (nodo_actual != NULL && nodo_actual->id != index)
            { // Mientras el nodo actual no sea NULL, el nombre no coincida...
                nodo_anterior = nodo_actual;
                nodo_actual = nodo_actual->siguiente;
            }

            if (nodo_actual != NULL)
            {
                if (nodo_anterior == NULL)
                {
                    cabeza = nodo_actual->siguiente;
                }
                else
                {
                    nodo_anterior->siguiente = nodo_actual->siguiente;
                }
                delete nodo_actual;
                cout << "Se elimino la cancion.";
            }
            else
            {
                cout << "No se enontro la cancion a borrar";
            }
        }
        else
        {
            cout << "No hay canciones en la Store";
        }
        getwchar();
    }

    // Metodo que recorre la lista de canciones comprando por string nombre
    Cancion *buscarCancionPorNombre(string nombre)
    {
        NodoCancion *nodo_actual = cabeza;

        while (nodo_actual != NULL)
        {
            if (nodo_actual->cancion->getNombre() == nombre)
            {
                cout << "Nombre: " << nodo_actual->cancion->getNombre() << ", Path: " << nodo_actual->cancion->getPath() << ", Indice en Store: " << nodo_actual->id << endl;
                return nodo_actual->cancion;
            }
            nodo_actual = nodo_actual->siguiente;
        }
        cout << "No se enontro la cancion" << endl;
        return NULL;
    }

    // Metodo que recorre la lista de canciones comprando por int indice
    Cancion *buscarCancionPorIndex(int index)
    {
        NodoCancion *nodo_actual = cabeza;

        while (nodo_actual != NULL)
        {
            if (nodo_actual->id == index)
            {
                cout << "Id en Store: " << nodo_actual->id << ", Nombre: " << nodo_actual->cancion->getNombre() << ", Path: " << nodo_actual->cancion->getPath() << "." << endl;
                return nodo_actual->cancion;
            }
            nodo_actual = nodo_actual->siguiente;
        }
        cout << "No se enontro la cancion" << endl;
        return NULL;
    }

    // Metodo que recorre las canciones
    void listarCanciones()
    {
        NodoCancion *nodo_actual = cabeza;

        if (nodo_actual == NULL)
        {
            {
                cout << "\nNo hay canciones registradas" << endl;
                return;
            }
        }

        cout << "\n\t \"Lista de Canciones\"" << endl;

        while (nodo_actual != NULL)
        {
            cout << nodo_actual->id << ". " << nodo_actual->cancion->getNombre() << "- " << nodo_actual->cancion->getPath() << "." << endl;
            nodo_actual = nodo_actual->siguiente;
        }
        cout << "\tFin" << endl;
    }
};