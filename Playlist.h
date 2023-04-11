#include <iostream>
#include <string>

using namespace std;

class Playlist
{
private:
    string nombre;

private:
    string descripcion;

private:
    ListaDobleCancionesPlaylist *listaCancionesPlaylist;

    // Constructor
public:
    Playlist(string nombre, string descripcion, ListaDobleCancionesPlaylist *listaCancionesPlaylist)
    {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->listaCancionesPlaylist = listaCancionesPlaylist;
    }

    // Getters y Setters
public:
    string getNombre()
    {
        return this->nombre;
    }

public:
    string getDescripcion()
    {
        return this->descripcion;
    }

public:
    ListaDobleCancionesPlaylist *getListaCancionesPlaylists() { return this->listaCancionesPlaylist; }

public:
    void setDescripcion(string descripcion)
    {
        this->descripcion = descripcion;
    }

public:
    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }
};
