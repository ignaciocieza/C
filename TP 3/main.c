#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"

int main()
{
    char seguir='s';
    int opcion;
    ArrayList *pArrayList;
    Movie *pMovie;

    pArrayList= al_newArrayList();
    pMovie=(Movie*) malloc(sizeof(Movie));

    cargarArchivoDeMovie(pArrayList);


    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula.\n");
        printf("2- Borrar pelicula.\n");
        printf("3- Modificar Pelicula.\n");
        printf("4- Generar pagina web.\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(pMovie, pArrayList);
                break;
            case 2:
                borrarPelicula(pArrayList);
                break;
            case 3:
                modificarPelicula(pArrayList);
                break;
            case 4:
                generarPagina(pArrayList);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion incorrecta");
        }
    }

    return 0;

}
