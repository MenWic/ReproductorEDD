#include <iostream>
#include <string>

using namespace std;

struct NodoPlayList
{
    NodoPlayList *siguiente;
    Playlist *playList;
    int id;

    // Constructor
    NodoPlayList(Playlist *playList, int id)
    {
        this->siguiente = NULL;
        this->playList = playList;
        this->id = id;
    }
};
