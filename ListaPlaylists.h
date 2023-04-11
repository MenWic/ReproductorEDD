#include <iostream>
#include <string>

using namespace std;

struct ListaPlaylists
{
    NodoPlayList *cabeza;
    int size;

    // Constructor
    ListaPlaylists()
    {
        cabeza = NULL;
        size = 0;
    }

    /*  Metodos Principales de Lista Enlazada   */
    // Function: @agregarNodo(), Metodo para incersion de nodos a la Lista Enlazada
    void agregarPlayList(Playlist *playlist)
    {
        NodoPlayList *nuevo_nodo = new NodoPlayList(playlist, this->size); // NodoCancion()

        if (cabeza == NULL)
        { // Cuando no hay ningun nodo creado aun...
            cabeza = nuevo_nodo;
        }
        else
        {
            NodoPlayList *nodo_actual = cabeza;
            while (nodo_actual->siguiente != NULL)
            {                                         // Mientras el siguiente del nodo evaluado no sea null...
                nodo_actual = nodo_actual->siguiente; // Seguir moviendonos al siguiente hasta encontrar el NULL
            }
            nodo_actual->siguiente = nuevo_nodo; // Al haber encontrado el NULL, creamos o setteamos nuestro nodo a crear
        }
        cout << "Se guardo la playlist" << endl;
        size++;
    }

    // Function: @eliminarNodo(), Metodo para eliminacion de nodos de la Lista Enlazada
    void eliminarPlayListPorIndex(int index)
    { // Param: atributo nombre del nodo que deseamos eliminar
        NodoPlayList *nodo_actual = cabeza;
        NodoPlayList *nodo_anterior = NULL;

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
            cout << "Se elimino la playlist" << endl;
        }
        else
        {
            cout << "No se enontro la playlist a borrar" << endl;
        }
    }

    // Funcion...
    Playlist *buscarPlayListPorIndex(int index)
    {
        NodoPlayList *nodo_actual = cabeza;

        while (nodo_actual != NULL)
        {
            if (nodo_actual->id == index)
            {
                return nodo_actual->playList;
            }
            nodo_actual = nodo_actual->siguiente;
        }
        return NULL;
    }

    // Funcion...
    void actualizarPlayListPorIndex(int index, string nombre, string descripcion)
    {
        NodoPlayList *nodo_actual = cabeza;

        while (nodo_actual != NULL)
        {
            if (nodo_actual->id == index)
            {
                cout << "Se actualizaron los datos de la playlist" << endl;
                nodo_actual->playList->setDescripcion(descripcion);
                nodo_actual->playList->setNombre(nombre);
            }
            nodo_actual = nodo_actual->siguiente;
        }
        cout << "No se enontro la playlist" << endl;
    }

    // Funcion...
    void listarPlayList()
    {
        NodoPlayList *nodo_actual = cabeza;

        if (nodo_actual == NULL)
        {
            cout << "No hay playlist registradas" << endl;
            return;
        }
        cout << "\n\tLISTA DE PLAYLIST'S " << endl;

        while (nodo_actual != NULL)
        {
            cout << "Id: " << nodo_actual->id << ", Nombre: " << nodo_actual->playList->getNombre() << ", Descrip: " << nodo_actual->playList->getDescripcion() << endl;

            nodo_actual = nodo_actual->siguiente;
        }
    }
};