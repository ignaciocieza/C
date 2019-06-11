#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "ArrayList.h"
#include "funciones.h"
#include "validacion.h"
#include "paginaWeb.h"



void cargarArchivoDeMovie(ArrayList *pElement)
{
    FILE *pMovie= fopen("peliculas.bin","r");
    Movie *pPelicula;

    if(pMovie != NULL)
    {
        while(feof(pMovie))
        {
            if(fread(pPelicula,sizeof(Movie),1,pMovie))
            {
                al_add(pElement,pPelicula);
                pPelicula= (Movie*) malloc(sizeof(Movie));
            }
            else
            {
                printf("\nError, en cargar archivo.\n");
            }
        }

        free(pPelicula);
        fclose(pMovie);
    }
}


void agregarPelicula(Movie* pMovie, ArrayList* pLista)
{
    int retorno=0;
    int i;
    pMovie= (Movie*) malloc (sizeof(Movie));
    FILE* peliculas = fopen("peliculas.bin", "w");

    if(pMovie != NULL)
    {
        retorno=1;
        if(!movie_setTitulo(pMovie))
        {
            if(!movie_setGenero(pMovie))
            {
                if(!movie_setDescripcion(pMovie))
                {
                    if(!movie_setLinkImagen(pMovie))
                    {
                        if(!movie_setDuracion(pMovie))
                        {
                            if(!movie_setPuntaje(pMovie))
                            {
                                movie_setId(pMovie);
                                movie_setIsEmpty((pMovie),0);
                                al_add(pLista,pMovie);

                                if(peliculas != NULL)
                                {
                                    retorno=1;
                                    for(i=0; i<al_len(pLista);i++)
                                    {
                                        fwrite(al_get(pLista, i), sizeof(Movie), 1, peliculas);
                                    }
                                    fclose(peliculas);

                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (!retorno)
    {
        printf("\nError, en la carga de la pelicula, reintente.\n");
    }
}

void borrarPelicula (ArrayList* pLista)
{
    Movie *auxPmovie;
    FILE* peliculas = fopen("peliculas.bin", "w");
    int auxIdUno;
    int auxIdDos;
    int retorno=0;
    char auxTitulo[20];
    int i;

 //--------Imprime Titulo e Id de las Peliculas cargadas-------//
    if(pLista != NULL)
    {
        for(i = 0; i< al_len(pLista);i++)
        {
            movie_getId(al_get(pLista,i),&auxIdUno);
            movie_getTitulo(al_get(pLista,i), auxTitulo);
            printf("\nTitulo de la Pelicula: %s ",auxTitulo);
            printf("\nID de la Pelicula: %d ",auxIdUno);
        }
    }
    else
    {
        printf("\nNo hay peliculas cargadas.\n");
    }
   //---------------Ingresar Id y borrar la pelicula--------------------------//


   if(!getValidInt("\n\nIngrese el Id de la pelicula a borrar:\n","\nEl Id ingresado no es valido, reintente.\n", &auxIdDos,0,9999,2))
   {
        for(i = 0; i< al_len(pLista);i++)
        {
            movie_getId(al_get(pLista,i),&auxIdUno);
            if(auxIdUno == auxIdDos)
            {
                auxPmovie = al_pop(pLista, i);
                movie_delete(auxPmovie);
                if(peliculas != NULL)
                {
                    for(i=0; i<al_len(pLista);i++)
                    {
                        fwrite(al_get(pLista, i), sizeof(Movie), 1, peliculas);
                    }
                    fclose(peliculas);
                    printf("\nLa Pelicula, ha sido borrada.\n");
                    retorno=1;
                }

            }

        }
        if(!retorno)
        {
            printf("\nEl Id, no coincide con los id de peliculas cargadas.");
        }
   }
}

void modificarPelicula (ArrayList* pLista)
{
    Movie *auxPmovie;
    FILE* peliculas = fopen("peliculas.bin", "w");
    int auxIdUno;
    int auxIdDos;
    int retorno=0;
    char auxTitulo[20];
    int i;

 //--------Imprime Titulo e Id de las Peliculas cargadas-------//
    if(pLista != NULL)
    {
        for(i = 0; i< al_len(pLista);i++)
        {
            movie_getId(al_get(pLista,i),&auxIdUno);
            movie_getTitulo(al_get(pLista,i), auxTitulo);
            printf("\nTitulo de la Pelicula: %s ",auxTitulo);
            printf("\nID de la Pelicula: %d ",auxIdUno);
        }
    }
    else
    {
        printf("\nNo hay peliculas cargadas.\n");
    }
   //---------------Ingresar Id y Modificar la pelicula--------------------------//


   if(!getValidInt("\n\nIngrese el Id de la pelicula a Modificar:\n","\nEl Id ingresado no es valido, reintente.\n", &auxIdDos,0,9999,2))
   {
        for(i = 0; i< al_len(pLista);i++)
        {
            movie_getId(al_get(pLista,i),&auxIdUno);
            if(auxIdUno == auxIdDos)
            {
                auxPmovie = al_get(pLista, i);
                if(auxPmovie != NULL)
                    if(!movie_setTitulo(auxPmovie))
                        if(!movie_setGenero(auxPmovie))
                            if(!movie_setDescripcion(auxPmovie))
                                if(!movie_setLinkImagen(auxPmovie))
                                    if(!movie_setDuracion(auxPmovie))
                                        if(!movie_setPuntaje(auxPmovie))
                                        {
                                            auxPmovie->id=auxIdUno;
                                            movie_setIsEmpty((auxPmovie),0);

                                            if(peliculas != NULL)
                                            {
                                                for(i=0; i<al_len(pLista);i++)
                                                {
                                                    fwrite(al_get(pLista, i), sizeof(Movie), 1, peliculas);
                                                }
                                                fclose(peliculas);
                                                printf("\nLa Pelicula, ha sido borrada.\n");
                                                retorno=1;
                                            }
                                        }
            }

        }
        if(!retorno)
        {
            printf("\nEl Id, no coincide con los id de peliculas cargadas.");
        }
   }
}

void generarPagina( ArrayList* pLista)
{
    char nombreArchivo[20];

    if(!getValidString("\nIngrese el nombre del archivo a generar\n", "\nNo es valido\n", "\nEl maximo es 20\n", nombreArchivo, 20, 2))
        generarPaginaWeb(nombreArchivo, pLista);
}

