#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"

typedef struct{

    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int id;
    int isEmpty;

}Movie;

void cargarArchivoDeMovie(ArrayList *pElement);
void agregarPelicula(Movie* pMovie, ArrayList* pLista);
void borrarPelicula (ArrayList* pLista);
void modificarPelicula (ArrayList* pLista);
void generarPagina( ArrayList* pLista);

#endif // FUNCIONES_H_INCLUDED
