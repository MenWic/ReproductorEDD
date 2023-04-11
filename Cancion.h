#include <iostream>
#include <string>

using namespace std;

class Cancion
{
private:
    string nombre;

private:
    string path;

    // Constructor
public:
    Cancion(string nombre, string path)
    {
        this->nombre = nombre;
        this->path = path;
    }

    //Getters y Setters
public:
    string getNombre()
    {
        return this->nombre;
    }

public:
    string getPath()
    {
        return this->path;
    }
};