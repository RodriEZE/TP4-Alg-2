
#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <fstream>
#include <iostream>
#include <sstream>

#include "Pelicula.h"
#include "Excepcion.h"

using namespace std;

const string ARCHIVO_VISTAS = "peliculas_vistas.txt";
const string ARCHIVO_NO_VISTAS = "peliculas_no_vistas.txt";

class Archivo {

private:

	string titulo, genero, director, puntaje, actores;
	bool abrio_vistas;
	bool abrio_no_vistas;
	Excepcion excepcion;

	bool comparar_archivos(string archivo);
	void chequear_archivo(string archivo);
	void cargar_listas(Lista<Pelicula*> &lista, ifstream* archivo);

public:

	/*
	 * PRE: -
	 * POST: Construye un objeto de tipo Archivo
	 */
	Archivo();

	/*
	 * PRE: Recibe un puntero a una lista y un string
	 * POST: Cierra los archivos correctamente
	 */
	void abrir_archivos(Lista<Pelicula*> & lista, string archivo);

	/*
	* PRE: -
	* POST: Devuelve un booleano
	*/
	bool obtener_abrio_vistas();

	/*
	* PRE: -
	* POST: Devuelve un booleano
	*/
	bool obtener_abrio_no();

	/*
	* PRE: Existe el objeto
	* POST: Destruye el objeto
	*/
	void verificar_ex();
};

#endif /* ARCHIVO_H_ */
