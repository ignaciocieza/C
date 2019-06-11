#ifndef PAGINAWEB_H_INCLUDED
#define PAGINAWEB_H_INCLUDED
#include "funciones.h"

/**
 *  Genera los archivos necesarios para armar la pagina web, utilizando las peliculas cargadas en el array
 * \param nombre char* Nombre del archivo a generar sin extension
 * \param pArrayPeliculas ArrayList*
 * \return int [0]OK [-1]Error
 *
 */
int generarPaginaWeb(char* nombre, ArrayList* pArrayPeliculas);


#endif // PAGINAWEB_H_INCLUDED
