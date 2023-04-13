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

    cout << "Ingrese direccion del archivo de carga en formato XM\nSi su archivo esta en la raiz del proyecto, ingrese el \"[nombre].xml\"" << endl;
    cin.ignore();
    getline(cin, xmlPath);         // lectura del path
    doc.LoadFile(xmlPath.c_str()); // Captura del texto

    if (doc.Error())
    { // Verifica si hay un error del archivo
        cout << "Error al cargar el archivo XML, path: " << xmlPath << endl;
        return;
    }

    XMLElement *insert = doc.FirstChildElement("Insertar"); //<Insertar> </Insertar>

    while (insert != nullptr) // Recorre los insert
    {
        cout << "Canciones leidas: " << endl;
        XMLElement *cancioN = insert->FirstChildElement("cancion");

        while (cancioN != nullptr)
        {
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
                cout << "\tNombre: " << nombre << ", Path: " << path << endl;
            }
            else
            {
                cout << "Todos los parametros deben de estar llenos porfavor" << endl;
            }
            cancioN = cancioN->NextSiblingElement("cancion");
        }

        XMLElement *playlist = insert->FirstChildElement("Lista");

        while (playlist != nullptr)
        {
            string nombrePlaylist;
            string descripcionPlaylist;

            nombrePlaylist = playlist->FirstChildElement("Nombre")->GetText();
            descripcionPlaylist = playlist->FirstChildElement("Description")->GetText();
            XMLElement *canciones = playlist->FirstChildElement("Canciones");

            if (!nombrePlaylist.empty() && !descripcionPlaylist.empty())
            { 
                // Agrega una playList sin canciones
                cout << "Nueva Lista de Reproduccion:" << endl;
                cout << "Nombre: " << nombrePlaylist << "\tDescripcion: " << descripcionPlaylist << endl;

                if (canciones != nullptr)
                { 
                    // Agrega playlist con canciones
                    cout << "Posicion de canciones:" << endl;
                    XMLElement *cancionesPlaylist = playlist->FirstChildElement("pos");

                    while (cancionesPlaylist != nullptr)
                    {
                        cout << cancionesPlaylist->GetText() << ", ";
                        cancionesPlaylist = cancionesPlaylist->NextSiblingElement("pos");
                    }
                    cout << endl;
                }
                else
                {
                    cout << "Fin lectura de canciones" << endl;
                }
            }
            else
            {
                cout << "Hay uno o mas campos vacios" << endl;
            }
            playlist = playlist->NextSiblingElement("Lista");
        }
        insert = insert->NextSiblingElement("Insertar");
    }

    XMLElement *eliminar = doc.FirstChildElement("Eliminar");

    while (eliminar != nullptr)
    {
        cout << "Eliminar leidos:" << endl;
        XMLElement *canciones = eliminar->FirstChildElement("cancion");

        while (canciones != nullptr)
        {
            cout << "\tCanciones leidas:" << endl;
            XMLElement *id = canciones->FirstChildElement("id");
            XMLElement *name = canciones->FirstChildElement("Nombre");

            if (id != nullptr)
            {
                std::cout << "\t\tId: " << id->GetText() << endl;
            }
            if (name != nullptr)
            {
                std::cout << "\t\tNombre: " << name->GetText() << endl;
            }
            canciones = canciones->NextSiblingElement("cancion");
        }
        eliminar = eliminar->NextSiblingElement("Eliminar");
    }
}