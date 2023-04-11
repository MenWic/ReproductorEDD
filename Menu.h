#include <iostream>
#include <string>

// #include <windows.h>

#include "Cancion.h"
#include "NodoCancion.h"
#include "ListaCancionesStore.h" //Alberga canciones en la Store

#include "NodoDobleCancion.h"
#include "ListaDobleCancionesPlaylist.h" //Alberga canciones de una Playlist
#include "Playlist.h"

#include "NodoPlaylist.h"
#include "ListaPlaylists.h" //Albergara las playlist que a su vez, contienen listas de canciones (Desarrollando)

using namespace std;

/*	--------- INIT Declaracion de Metodos ---------	*/
void pausa();
int reproducir();

// Funciones para apartado: CANCIONES
void menuCanciones(ListaCancionesStore *listaCanciones);
void insertarCancionAStore(ListaCancionesStore *listaCanciones);
void buscarCancionPorNombre(ListaCancionesStore *listaCanciones);
void eliminarCancionDeStore(ListaCancionesStore *listaCanciones);

// Funciones para apartado: PLAYLIST'S
void menuPlaylists(ListaPlaylists *listaPlaylists, ListaCancionesStore *listaCanciones);
void crearPlaylist(ListaPlaylists *listaPlaylists, ListaCancionesStore *listaCanciones);
void eliminarPlaylist(ListaPlaylists *listaPlaylists);
void actualizarPlaylist(ListaPlaylists *listaPlaylists); // Pendiente
void listarPlaylist(ListaPlaylists *listaPlaylists);
void agregarCancionesAPlaylist(ListaCancionesStore *listaCanciones, ListaPlaylists *listaPlaylists);
void eliminarCancionesDePlaylist(ListaPlaylists *listaPlaylists);

// void agregarPlaylist(ListaDobleCancionesPlaylist *ListaDobleCancionesPlaylist); //Implementado por crearPlaylist
// void eliminarPlaylist(ListaDobleCancionesPlaylist *ListaDobleCancionesPlaylist); //Implementado por eliminarPlaylist
/*	--------- FIN Declaracion de Metodos ---------	*/

// Metodo de Menu principal
int main()
{
	// int reproducir();

	ListaCancionesStore *listaCanciones = new ListaCancionesStore(); // Lista de Canciones en la Store
	ListaPlaylists *listaPlaylists = new ListaPlaylists();			 // Lista de Playlist creadas
	// ListaDobleCancionesPlaylist *listaCancionesEnPlaylist = new ListaDobleCancionesPlaylist(); //Lista de canciones dentro de Playlist

	bool bandera = false;
	char tecla;

	do
	{
		system("cls");
		cout << "\tR E P R O D U C T O R" << endl;
		cout << "\t- - - - - - - - - - -" << endl
			 << endl;
		cout << "\t1. Canciones" << endl;
		cout << "\t2. Playlist's" << endl;
		cout << "\t3. Reproduccion" << endl;
		cout << "\t4. Carga Masiva (Archivo XML)" << endl;
		cout << "\t5. Salir" << endl
			 << endl;
		cout << "Elige una opcion: ";
		cin >> tecla;

		switch (tecla)
		{
		case '1':
			system("cls");
			menuCanciones(listaCanciones);

			pausa();
			break;

		case '2':
			system("cls");
			menuPlaylists(listaPlaylists, listaCanciones);

			pausa();
			break;

		case '3':
			system("cls");
			cout << "FASE NO TERMINADA (EN DESARROLLO)...\n";
			pausa();
			break;

		case '4':
			system("cls");
			cout << "FASE MENOS TERMINADA (X).\n";
			pausa();
			break;

		case '5':
			system("cls");
			bandera = true;
			break;

		default:
			system("cls");
			cout << "La Opcion no es valida...\a" << endl;
			pausa();
			break;
		}
	} while (bandera != true);

	return 0;
}

/***********************************
 * Metodos Principales: CANCIONES *
 ***********************************/
void menuCanciones(ListaCancionesStore *listaCanciones)
{
	char opc;
	system("cls");
	cout << "\t CANCIONES " << endl;
	cout << "\t- - - - - -" << endl
		 << endl;
	cout << "\t1. Insertar Cancion";
	cout << "\t2. Eliminar Cancion";
	cout << "\t3. Buscar Cancion";
	cout << "\t4. Listar Canciones";
	cout << "\t5. Regrsar al Menu" << endl
		 << endl;
	cout << "\tElige una opcion: ";
	cin >> opc;

	switch (opc)
	{
		system("cls");
	case '1':
		insertarCancionAStore(listaCanciones);
		// pausa();
		break;
	case '2':
		eliminarCancionDeStore(listaCanciones);
		break;
	case '3':
		buscarCancionPorNombre(listaCanciones);
		break;
	case '4':
		listaCanciones->listarCanciones();
		break;

	default:
		break;
	}
}

// Funcion insertar canciones a Lista de Canciones (store)
void insertarCancionAStore(ListaCancionesStore *listaCanciones)
{
	string path;
	string nombre;

	bool bandera = true;

	while (bandera)
	{
		cout << "\n\tINSERTAR CANCION " << endl;
		cout << "Nombre de Cancion: ";
		// cin >> nombre;
		cin.ignore();
		getline(cin, nombre);
		cout << "Path de Cancion: ";
		// cin >> path;
		cin.ignore();
		getline(cin, path);

		if (nombre != "" && path != "")
		{
			bandera = false;
		}
		else
		{
			cout << "\tParametros vacios o nulos" << endl;
		}
	}
	listaCanciones->agregarCancion(nombre, path);
}

// Funcion para elimminar canciones de la lista de canciones (store)
void eliminarCancionDeStore(ListaCancionesStore *listaCanciones)
{
	char x, confirmation;
	string nombre;
	int index;

	system("cls");
	cout << "\n\t ELIMINAR CANCION " << endl;
	listaCanciones->listarCanciones(); // Mostrar canciones para facilitar datos previo a eliminacion

	cout << "1. Borrar por nombre" << endl
		 << "2. Borrar por id" << endl;
	cin >> x;

	switch (x)
	{
	case '1':
		cout << "Ingrese el nombre de la cancion: ";
		// cin >> nombre;
		cin.ignore();
		getline(cin, nombre);

		if (listaCanciones->buscarCancionPorNombre(nombre) != NULL)
		{
			cout << "Confirmar eliminacion (y/Y): ";
			cin >> confirmation;

			if (confirmation == 'y' || 'Y')
			{
				listaCanciones->eliminarCancionPorNombre(nombre);
				// Ya se elimino, el mensaje esta en el metodo eliminarCancionPorNombre()
			}
			else
			{
				cout << "No se elimino la cancion" << endl;
			}
		}
		break;

	case '2':
		cout << "Ingrese el id de la cancion: ";
		cin >> index;

		if (listaCanciones->buscarCancionPorIndex(index) != NULL)
		{
			cout << "Confirmar eliminacion (1): ";
			cin >> confirmation;

			if (confirmation == '1')
			{
				listaCanciones->eliminarCancionPorIndex(index);
				cout << "Se elimino la cancion" << endl;
			}
			else
			{
				cout << "No se elimino la cancion" << endl;
			}
		}
		break;

	default:
		cout << "Opcion no valida" << endl;
		break;
	}
}

// Funcion que compara un valor "nombre" con el atributo nombre de las canciones almacenadas en Store
void buscarCancionPorNombre(ListaCancionesStore *listaCanciones)
{
	string nombre;
	bool bandera = true;

	while (bandera)
	{
		cout << "\n\t BUSCAR CANCION" << endl;
		cout << "Nombre de Cancion: " << endl;
		// cin >> nombre;
		cin.ignore();
		getline(cin, nombre);

		if (nombre != "")
		{
			bandera = false;
		}
		else
		{
			cout << "Parametros vacios o nulos" << endl;
		}
	}
	listaCanciones->buscarCancionPorNombre(nombre);
}

/*********************************
 * Metodos Principales: PLAYLIST *
 *********************************/
void menuPlaylists(ListaPlaylists *listaPlaylists, ListaCancionesStore *listaCanciones)
{
	char opc;

	cout << "\t PLAYLIST " << endl;
	cout << "\t- - - - - -" << endl
		 << endl;
	cout << "\t1. Crear Playlist"; // Listo
	cout << "\t2. Eliminar Playlist";
	cout << "\t3. Actualizar Playlist";
	cout << "\t4. Listar Playlists credas" << endl; // Listo
	cout << "\t5. Agregar canciones a Playlist";	// Listo
	cout << " \t6. Eliminar canciones de Playlist"; // Listo
	cout << "\t7. Regrsar al Menu" << endl;
	cout << "\tElije una opcion: ";
	cin >> opc;

	switch (opc)
	{
	case '1':
		system("cls");
		crearPlaylist(listaPlaylists, listaCanciones);
		// pausa();
		break;
	case '2':
		eliminarPlaylist(listaPlaylists); // listaCanciones
		break;
	case '3':
		actualizarPlaylist(listaPlaylists);
		break;
	case '4':
		listarPlaylist(listaPlaylists);
		break;
	case '5':
		agregarCancionesAPlaylist(listaCanciones, listaPlaylists);
		break;
	case '6':
		eliminarCancionesDePlaylist(listaPlaylists);
		break;

	default:
		break;
	}
}

// Funcion para crear una Playlist en una lista de Playlists que a su vez, dicha Playlist contendra una lista de Canciones
void crearPlaylist(ListaPlaylists *listaPlaylists, ListaCancionesStore *listaCanciones)
{
	ListaDobleCancionesPlaylist *listaCancionesEnPlaylist = new ListaDobleCancionesPlaylist();
	int id;
	string nombre;
	string descripcion;

	cout << "\n\t CREAR PLAYLIST " << endl;
	cout << "Ingrese el nombre de la playlist" << endl;
	// cin >> nombre;
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese descripcion de la playlist" << endl;
	// cin >> descripcion;
	cin.ignore();
	getline(cin, descripcion);

	while (true)
	{
		listaCanciones->listarCanciones();
		cout << "Ingrese Id de la cancion que agregara a la Playlist\n(-1. Salir y Guardar):";
		cin >> id;

		if (id == -1)
		{
			break;
		}
		Cancion *cancionEncontrada = listaCanciones->buscarCancionPorIndex(id);

		if (cancionEncontrada != NULL)
		{
			listaCancionesEnPlaylist->agregarCancion(cancionEncontrada);
		}
	}
	Playlist *nueva_playlist = new Playlist(nombre, descripcion, listaCancionesEnPlaylist);
	listaPlaylists->agregarPlayList(nueva_playlist);
}

// Funcion para eliminar Playlist de la lista de playlists
void eliminarPlaylist(ListaPlaylists *listaPlaylists)
{
	int idPLayList;
	// int idCancion;

	cout << "\n\t ELIMINAR PLAYLIST " << endl;
	listaPlaylists->listarPlayList();
	cout << "Ingrese el ID de la Playlist que desea eliminar de la lista: " << endl;
	cin >> idPLayList;

	Playlist *playlist = listaPlaylists->buscarPlayListPorIndex(idPLayList);
	listaPlaylists->eliminarPlayListPorIndex(idPLayList);
}

// PENDIENTEEEEEEEEEEEEE
void actualizarPlaylist(ListaPlaylists *listaPlaylists)
{
	int idPLayList;
	string nuevoNombrePlaylist;
	string nuevaDescripcionPlaylist;
	// int idCancion;

	cout << "\n\t ACTUALIZAR PLAYLIST " << endl;
	listaPlaylists->listarPlayList();
	cout << "Ingrese el ID de la Playlist que desea actualizar de la lista: " << endl;
	cin >> idPLayList;
	cout << "Ingrese el nuevo nombre de la Playlist: " << endl;
	// cin >> nuevoNombrePlaylist;
	cin.ignore();
	getline(cin, nuevoNombrePlaylist);
	cout << "Ingrese la nueva descripcion de la Playlist: " << endl;
	// cin >> nuevaDescripcionPlaylist;
	cin.ignore();
	getline(cin, nuevaDescripcionPlaylist);

	if (nuevoNombrePlaylist == "" || nuevaDescripcionPlaylist == "")
	{
		cout << "No se actualizo la Playlist (no se aceptan datos vacios)" << endl;
	}
	else
	{
		listaPlaylists->actualizarPlayListPorIndex(idPLayList, nuevoNombrePlaylist, nuevaDescripcionPlaylist);
	}
}

// Funcion para imprimir Playlists creadas
void listarPlaylist(ListaPlaylists *listaPlaylists)
{
	int id;

	cout << "\n\t LISTAR PLAYLIST'S " << endl;
	listaPlaylists->listarPlayList();
	cout << "Ingrese el ID de la Playlist a desplegar: " << endl;
	cin >> id;
	Playlist *playlist = listaPlaylists->buscarPlayListPorIndex(id);

	if (playlist != NULL)
	{

		playlist->getListaCancionesPlaylists()->imprimirCanciones();
	}
	else
	{
		cout << "No existe la playlist" << endl;
	}
}

// Funcion para agregar canciones a la lista Canciones de Playlist, que almacena cada Playlist de la lista de playlists
void agregarCancionesAPlaylist(ListaCancionesStore *listaCanciones, ListaPlaylists *listaPlaylists)
{
	int idPLayList;
	int idCancion;

	cout << "\n\t AGREGAR CANCION A PLAYLIST" << endl;
	listaPlaylists->listarPlayList();
	cout << "Ingrese el ID de la Playlist a la que desea agregar canciones: " << endl;
	cin >> idPLayList;

	Playlist *playlist = listaPlaylists->buscarPlayListPorIndex(idPLayList);

	if (playlist != NULL)
	{
		while (true)
		{
			listaCanciones->listarCanciones();
			cout << "Ingrese id de la cancion para agregarla a play list.\nPara salir y guardar(press -1)" << endl;
			cin >> idCancion;

			if (idCancion == -1)
			{
				break;
			}
			Cancion *cancionEncontrada = listaCanciones->buscarCancionPorIndex(idCancion);

			if (cancionEncontrada != NULL)
			{
				playlist->getListaCancionesPlaylists()->agregarCancion(cancionEncontrada);
			}
		}
	}
	else
	{
		cout << "No existe la playlist" << endl;
	}
}

// Funcion para eliminar canciones de la lista de canciones de playlist
void eliminarCancionesDePlaylist(ListaPlaylists *listaPlaylists)
{
	int idPLayList;
	int idCancion;

	cout << "\n\t ELIMINAR CANCION DE PLAYLIST" << endl;
	listaPlaylists->listarPlayList();
	cout << "Ingrese el ID de la Playlist a la que desea eliminar canciones: " << endl;
	cin >> idPLayList;

	Playlist *playlist = listaPlaylists->buscarPlayListPorIndex(idPLayList);

	if (playlist != NULL)
	{
		while (true)
		{
			playlist->getListaCancionesPlaylists()->imprimirCanciones();
			cout << "Ingrese Id de la cancion que agregara a la Playlist\n (-1. Salir y Guardar):" << endl;
			cin >> idCancion;

			if (idCancion == -1)
			{
				break;
			}
			playlist->getListaCancionesPlaylists()->eliminarCancion(idCancion);
		}
	}
	else
	{
		cout << "No existe la playlist" << endl;
	}
}

/**********************
 *	Funciones basicas *
 **********************/
void pausa()
{
	cout << "Pulsa una tecla para continuar...";
	getwchar();
	getwchar();
}

// No fuciono el path relativo ni absoluto, no reproduce el archivo
int reproducir()
{
	// char soundfile[] = "C:\CuttingShapes.wav";
	// cout <<PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);

	/* bool played = PlaySound(TEXT("C:\\Users\\lamr4\\Downloads\\CuttingShapes.wav"),tingShapes.wav NULL, SND_SYNC);
	 * cout << " Sucess or not " << played << endl;
	 */

	// system("pause");
	// return 0;
}
