#include <iostream>
#include <string>

#include "tinyxml2.cpp"
#include "tinyxml2.h" //Carga masiva
// #include "ListaCancionesStore.h"
// #include "ListaPlaylists.h"

// #include <tinyxml2.cpp>

using namespace std;
using namespace tinyxml2;

//Metodo que busca y analiza un archivo xml para extraer canciones o listas y mostrarlas ya procesadas (sin ensamblar a structs canciones o playlists)
void leerArchivoXML()
{
    XMLDocument doc;//Documento a leer
    string xmlPath; //Direccion/Path

    cout << "Ingrese direccion del archivo de carga en formato XM\nSi su archivo esta en la raiz del proyecto, ingrese el [nombre].xml" << std::endl;
    cin.ignore();
    getline(cin, xmlPath);         // lectura del path
    doc.LoadFile(xmlPath.c_str()); // Captura del texto

    if (doc.Error())
    { // Verifica si hay un error del archivo
        std::cout << "Error al carga el archivo XML, path: " << xmlPath << std::endl;
        return;
    }

    XMLElement *insert = doc.FirstChildElement("Insertar"); //<Insertar> </Insertar>
    // int vueltasInsert = 0;

    while (insert != nullptr) // Recorre los insert
    {
        // vueltasInsert++;
        std::cout << "Cancioens: " << std::endl;
        XMLElement *cancioN = insert->FirstChildElement("cancion");
        // int vCan = 0; // Saber cant iter.

        while (cancioN != nullptr)
        {
            // vCan++;
            string path;
            string nombre;
            string posId;
            nombre = cancioN->FirstChildElement("Nombre")->GetText(); // obtiene el nombre
            path = cancioN->FirstChildElement("path")->GetText();     // obtiene el path
            XMLElement *pos = cancioN->FirstChildElement("Pos");

            if (pos != nullptr)
            { // obtiene la posicion en caso de que este
                posId = pos->GetText();
            }
            if (!nombre.empty() && !path.empty())
            {
                std::cout << "\tNombre: " << nombre << "\tPath: " << path << std::endl;
            }
            else
            {
                std::cout << "Todos los parametros deben de estar llenos " << std::endl;
            }
            cancioN = cancioN->NextSiblingElement("cancion");
        }
        // listaCanciones->imprimirPos();
        XMLElement *playlist = insert->FirstChildElement("Lista");

        while (playlist != nullptr)
        {
            string nombrePlaylist;
            string descripcionPlaylist;

            nombrePlaylist = playlist->FirstChildElement("Nombre")->GetText();
            descripcionPlaylist = playlist->FirstChildElement("Description")->GetText();
            XMLElement *canciones = playlist->FirstChildElement("Canciones");

            if (!nombrePlaylist.empty() && !descripcionPlaylist.empty())
            { // Agrega Lista sin canciones
                std::cout << "Nueva Lista de Reproduccion" << std::endl;
                std::cout << "Nombre: " << nombrePlaylist << "\tDescripcion: " << descripcionPlaylist << std::endl;

                if (canciones != nullptr)
                { // Agrega playlist con canciones
                    std::cout << "Posicion de canciones" << std::endl;
                    XMLElement *cancionesPlaylist = playlist->FirstChildElement("pos");

                    while (cancionesPlaylist != nullptr)
                    {
                        cout << cancionesPlaylist->GetText() << "-";
                        cancionesPlaylist = cancionesPlaylist->NextSiblingElement("pos");
                    }
                    cout << endl;
                }
                else
                {
                    cout << "No hay mas canciones" << endl;
                }
            }
            else
            {
                std::cout << "Hay uno o mas campos vacios" << std::endl;
            }
            playlist = playlist->NextSiblingElement("Lista");
        }
        insert = insert->NextSiblingElement("Insertar");
    }

    XMLElement *eliminar = doc.FirstChildElement("Eliminar");

    while (eliminar != nullptr)
    {
        std::cout << "ELiminar" << std::endl;
        XMLElement *canciones = eliminar->FirstChildElement("cancion");

        while (canciones != nullptr)
        {
            std::cout << "\tCancion" << std::endl;
            XMLElement *id = canciones->FirstChildElement("id");
            XMLElement *name = canciones->FirstChildElement("Nombre");

            if (id != nullptr)
            {
                std::cout << "\t\tId: " << id->GetText() << std::endl;
            }
            if (name != nullptr)
            {
                std::cout << "\t\tNombre: " << name->GetText() << std::endl;
            }
            canciones = canciones->NextSiblingElement("cancion");
        }
        eliminar = eliminar->NextSiblingElement("Eliminar");
    }
}