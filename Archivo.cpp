
#include "Archivo.h"
#include "Listas.h"
#include "Pelicula.h"


Archivo::Archivo(){

	archivo_vistas.open(ARCHIVO_VISTAS);
	archivo_no_vistas.open(ARCHIVO_NO_VISTAS);
}

Archivo::~Archivo(){

	archivo_vistas.close();
	archivo_no_vistas.close();
}

void Archivo::cargar(Lista<Pelicula*> &lista_no_vistas){

	string separado;
	istringstream stream_actores;
	Pelicula* pelicula;

	if (!archivo_no_vistas.fail()){

		while(!archivo_no_vistas.eof()){

			getline(archivo_no_vistas, titulo);
			getline(archivo_no_vistas, genero);
			getline(archivo_no_vistas, puntaje);
			getline(archivo_no_vistas, director);
			getline(archivo_no_vistas, actores);

			stream_actores.str(actores);

			pelicula = new Pelicula (titulo, genero, stoi(puntaje), director);

			while (!stream_actores.eof()){

				stream_actores >> (separado);
				pelicula->agregar_actor(separado);
			}

			lista_no_vistas.insertar_dato(pelicula);

			if (!archivo_no_vistas.eof()) getline(archivo_no_vistas, titulo);

			stream_actores.clear();
		}
	}
}