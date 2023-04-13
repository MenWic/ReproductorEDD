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
#include "ListaPlaylists.h" //Albergara las playlist que a su vez, contienen listas de canciones
#include "CargaMasiva.h"

using namespace std;
// using namespace tinyxml2;

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

void menuReproduccion(ListaPlaylists *listaPlaylists);
void tipoReproduccion(ListaPlaylists *listaPlaylists, int idPlaylist);

void menuCargaMasiva();
void leerArchivoXML();

// void agregarPlaylist(ListaDobleCancionesPlaylist *ListaDobleCancionesPlaylist); //Implementado por crearPlaylist
// void eliminarPlaylist(ListaDobleCancionesPlaylist *ListaDobleCancionesPlaylist); //Implementado por eliminarPlaylist
/*	--------- FIN Declaracion de Metodos ---------	*/

// Metodo de Menu principal
int main()
{
	// int reproducir();
	ListaCancionesStore *listaCanciones = new ListaCancionesStore(); // Lista de Canciones en la Store
	ListaPlaylists *listaPlaylists = new ListaPlaylists();			 // Lista de Playlist creadas

	bool bandera = false;
	char tecla;

	do
	{
		//system("cls");
		cout << "\n\n\t- - - - - - - - - - - - - -" << endl;
		cout << "\t + R E P R O D U C T O R +" << endl;
		cout << "\t- - - - - - - - - - - - - -" << endl
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
			break;

		case '2':
			system("cls");
			menuPlaylists(listaPlaylists, listaCanciones);
			break;

		case '3':
			system("cls");
			cout << "Nota: Fase aun en desarrollo" << endl;
			menuReproduccion(listaPlaylists);
			break;

		case '4':
			system("cls");
			cout << "Nota: Fase aun en desarrollo" << endl;
			menuCargaMasiva();
			break;

		case '5':
			system("cls");
			bandera = true;
			break;

		default:
			system("cls");
			cout << "La opcion ingresada no es valida..." << endl;
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

	cout << "\t- - - - - -" << endl;
	cout << "\t CANCIONES " << endl;
	cout << "\t- - - - - -" << endl
		 << endl;
	cout << "\t1. Insertar Cancion";
	cout << "\t2. Eliminar Cancion";
	cout << "\t3. Buscar Cancion";
	cout << "\t4. Listar Canciones";
	cout << "\t5. Regresar al Menu" << endl
		 << endl;
	cout << "\tElige una opcion: ";
	cin >> opc;

	switch (opc)
	{
		system("cls");
	case '1':
		insertarCancionAStore(listaCanciones);
		break;
	case '2':
		eliminarCancionDeStore(listaCanciones);
		break;
	case '3':
		buscarCancionPorNombre(listaCanciones);
		break;
	case '4':
		system("cls");
		cout << "\n\t * LISTAR CANCIONOES *" << endl;
		listaCanciones->listarCanciones();
		pausa();
		getwchar();
		break;
	case '5':
		break;

	default:
		cout << "La opcion ingresada no es valida..." << endl;
		break;
	}
	// pausa();
}

// Funcion insertar canciones a Lista de Canciones (store)
void insertarCancionAStore(ListaCancionesStore *listaCanciones)
{
	string path;
	string nombre;

	bool bandera = true;

	while (bandera)
	{
		system("cls");
		cout << "\n\t * INSERTAR CANCION *" << endl;
		cout << "Nombre de Cancion: ";
		cin.ignore();
		getline(cin, nombre);
		cout << "Path de Cancion: ";
		cin.ignore();
		getline(cin, path);

		if (nombre != "" || path != "")
		{
			bandera = false;
		}
		else
		{
			cout << "\tParametros vacios o nulos" << endl;
		}
	}
	listaCanciones->agregarCancion(nombre, path);
	pausa();
}

// Funcion para elimminar canciones de la lista de canciones (store)
void eliminarCancionDeStore(ListaCancionesStore *listaCanciones)
{
	char x, confirmation;
	string nombre;
	int index;

	system("cls");
	cout << "\n\t * ELIMINAR CANCION *" << endl;
	// listaCanciones->listarCanciones(); // Mostrar canciones para facilitar datos previo a eliminacion

	cout << "\nComo eliminara la cancion?" << endl;
	cout << "1. Borrar por nombre" << endl
		 << "2. Borrar por id" << endl;
	cout << "3. Regresar al Menu" << endl;

	cout << "Ingrese su opcion: ";
	cin >> x;

	switch (x)
	{
	case '1':
		cout << "\nIngrese el nombre de la cancion: ";
		cin.ignore();
		getline(cin, nombre);

		if (listaCanciones->buscarCancionPorNombre(nombre) != NULL)
		{
			cout << "Confirmar eliminacion (s/S): ";
			cin >> confirmation;

			if (confirmation == 's' || 'S')
			{
				listaCanciones->eliminarCancionPorNombre(nombre);
			}
			else
			{
				cout << "No se elimino la cancion" << endl;
			}
		}
		pausa();
		getwchar();
		break;

	case '2':
		cout << "\nIngrese el id de la cancion: ";
		cin >> index;

		//Debe ser INT
		if (listaCanciones->buscarCancionPorIndex(index) != NULL)
		{
			cout << "Confirmar eliminacion (s/S): ";
			cin >> confirmation;

			if (confirmation == 's' || 'S')
			{
				listaCanciones->eliminarCancionPorIndex(index);
				cout << "Se elimino la cancion" << endl;
			}
			else
			{
				cout << "No se elimino la cancion" << endl;
			}
			pausa();
		} else {
			cout << "No se encontro la cancion" << endl;
			pausa();
		}
		getwchar();
		break;

	case '3':
		break;

	default:
		cout << "La opcion ingresada no es valida..." << endl;
		break;
		pausa();
	}
}

// Funcion que compara un valor "nombre" con el atributo nombre de las canciones almacenadas en Store
void buscarCancionPorNombre(ListaCancionesStore *listaCanciones)
{
	string nombre;
	bool bandera = true;

	while (bandera)
	{
		system("cls");
		cout << "\n\t * BUSCAR CANCION *" << endl;
		cout << "Ingrese el nombre de la cancion" << endl;
		cin.ignore();
		getline(cin, nombre);

		if (nombre != "")
		{
			bandera = false;
		}
		else
		{
			cout << "Ingrese un nombre (no deje vacio por favor)" << endl;
		}
	}
	listaCanciones->buscarCancionPorNombre(nombre);
	pausa();
}

/*********************************
 * Metodos Principales: PLAYLIST *
 *********************************/
void menuPlaylists(ListaPlaylists *listaPlaylists, ListaCancionesStore *listaCanciones)
{
	char opc;
	cout << "\t- - - - - -" << endl;
	cout << "\t PLAYLIST " << endl;
	cout << "\t- - - - - -" << endl
		 << endl;
	cout << "\t1. Crear Playlist"; // Listo
	cout << "\t2. Eliminar Playlist";
	cout << "\t3. Actualizar Playlist";
	cout << "\t4. Listar Playlists credas\n";		// Listo
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
	case '7':
		pausa();
		break;

	default:
		cout << "La opcion ingresada no es valida..." << endl;
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

	cout << "\n\t * CREAR PLAYLIST *" << endl;
	cout << "Ingrese los datos de la nueva Playlist" << endl;
	cout << "Nombre de la playlist: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Descripcion de la playlist: ";
	cin.ignore();
	getline(cin, descripcion);

	while (true)
	{
		listaCanciones->listarCanciones();
		cout << "(Opcion \"-1\" para Salir y Guardar)" << endl;
		cout << "Ingrese el Id de la cancion que agregara a la nueva Playlist: ";
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

	cout << "\n\t * ELIMINAR PLAYLIST *" << endl;
	listaPlaylists->recorrerListaDePlayList();
	cout << "Ingrese el Id de la Playlist que desea eliminar de la Playlist: ";
	cin >> idPLayList;

	Playlist *playlist = listaPlaylists->buscarPlayListPorIndex(idPLayList);
	listaPlaylists->eliminarPlayListPorIndex(idPLayList);
}

// Funcion que actualiza los datos de una Playlist creada previamente
void actualizarPlaylist(ListaPlaylists *listaPlaylists)
{
	int idPLayList;
	string nuevoNombrePlaylist;
	string nuevaDescripcionPlaylist;

	cout << "\n\t * ACTUALIZAR PLAYLIST *" << endl;
	listaPlaylists->recorrerListaDePlayList();
	cout << "Ingrese el Id de la Playlist que desea actualizar: " << endl;
	cin >> idPLayList;
	cout << "Ingrese los nuevos datos para la Playlist seleccionada" << endl;
	cout << "Nuevo nombre de Playlist: ";
	cin.ignore();
	getline(cin, nuevoNombrePlaylist);
	cout << "Nueva descripcion de Playlist: ";
	cin.ignore();
	getline(cin, nuevaDescripcionPlaylist);

	if ((nuevoNombrePlaylist == "" || nuevaDescripcionPlaylist == "") || (nuevoNombrePlaylist == "" && nuevaDescripcionPlaylist == ""))
	{
		cout << "No se actualizo la Playlist (Ambos datos deben ser cambiados)" << endl;
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

	cout << "\n\t * LISTAR PLAYLIST'S *" << endl;
	listaPlaylists->recorrerListaDePlayList();
	cout << "Ingrese el Id de la Playlist a desplegar: ";
	cin >> id;
	Playlist *playlist = listaPlaylists->buscarPlayListPorIndex(id);

	if (playlist != NULL)
	{

		playlist->getListaCancionesPlaylists()->imprimirCanciones();
	}
	else
	{
		cout << "La Playlist esta vacia" << endl;
	}
}

// Funcion para agregar canciones a la lista Canciones de Playlist, que almacena cada Playlist de la lista de playlists
void agregarCancionesAPlaylist(ListaCancionesStore *listaCanciones, ListaPlaylists *listaPlaylists)
{
	int idPLayList;
	int idCancion;

	cout << "\n\t * AGREGAR CANCION A PLAYLIST *" << endl;
	cout << "Eliga por Id, la Playlist a la que desea agregar canciones: " << endl;
	listaPlaylists->recorrerListaDePlayList();
	cout << "Id de Playlist: ";
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
	listaPlaylists->recorrerListaDePlayList();
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

/************************************
 * Metodos Principales: REPRODUCCION *
 ************************************/

void menuReproduccion(ListaPlaylists *listaPlaylist)
{
	int idPlaylist;

	listaPlaylist->recorrerListaDePlayList();

	cout << "Elige la playlist que deseas reproducir (Id):";
	cin >> idPlaylist;
	tipoReproduccion(listaPlaylist, idPlaylist);
}

void tipoReproduccion(ListaPlaylists *listaPlaylists, int idPlaylist)
{
	char opc;
	Playlist *pl;
	cout << "\t- - - - - - - " << endl;
	cout << "\t REPRODUCCION " << endl;
	cout << "\t- - - - - - - " << endl
		 << endl;
	cout << "Elige la forma en que desea reproducri su Playlist" << endl;
	cout << " 1. Reproduccion normal" << endl;
	cout << " 2. Reproduccion repetida (bucle)" << endl;
	cout << " 3. Salir" << endl;
	cout << "\tElige una opcion: ";
	cin >> opc;

	switch (opc)
	{
	case '1':
	{
		system("cls");
		pl = listaPlaylists->buscarPlayListPorIndex(idPlaylist);
		pl->getListaCancionesPlaylists()->reproducirNormal();
	}
	break;

	case '2':
	{
		pl = listaPlaylists->buscarPlayListPorIndex(idPlaylist);
		pl->getListaCancionesPlaylists()->reproducirInfinita();
		// reproduccionCircular(listaPlaylists); // listaCancionesFZ
	}
	break;
	case '3':
	{
		system("cls");
	}

	default:
		cout << "Opcion no valida" << endl;
		break;
	}
}

/***************************
 *	Funciones Carga Masiva *
 ***************************/
void menuCargaMasiva()
{
	char opc;
	cout << "\t- - - - - - - " << endl;
	cout << "\t CARGA MASIVA " << endl;
	cout << "\t- - - - - - - " << endl
		 << endl;
	cout << "Lectura de Archivo (.xml)" << endl;
	cout << " 1. Cargar y leer archivo" << endl;
	cout << " 2. Regresar al Menu" << endl;
	cout << "Elige una opcion: ";
	cin >> opc;

	switch (opc)
	{
	case '1':
	{
		system("cls");
		leerArchivoXML();
	}
	break;

	case '2':
	{
		system("cls");
		// pausa();
		break;
	}
	break;

	default:
		cout << "La opcion ingresada no es valida..." << endl;
		break;
	}
}

/**********************
 *	Funciones basicas *
 **********************/
void pausa()
{
	cout << "Pulsa una tecla para continuar...";
	getwchar();
	// getwchar();
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