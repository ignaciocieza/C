#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "paginaWeb.h"
#include "validacion.h"
#include "funciones.h"

static void escribirPelicula(FILE* pFile, Movie* pelicula);
static int copiarTemplate(char* rutaNueva);

int generarPaginaWeb(char* nombre, ArrayList* pArrayPeliculas)
{
    int retorno = -1;
    if(!copiarTemplate(nombre))
    {
        int i;
        FILE* pFile = fopen("archivos\\peliculas.html", "w");
        if(pFile != NULL)
        {
            retorno = 0;
            for(i=0;i<al_len(pArrayPeliculas);i++)
            {
                escribirPelicula(pFile, al_get(pArrayPeliculas, i));
            }
            fclose(pFile);
        }
    }
    return retorno;
}

static int copiarTemplate(char* path)
{
    int retorno = -1;
    int caracter;
    FILE* templateMovie = fopen("archivos\\template.html", "r");
    FILE* nuevaPagina = fopen(strcat(path,".html"), "w");

    if(templateMovie != NULL && nuevaPagina != NULL)
    {
        retorno = 0;
        caracter = fgetc(templateMovie);
        while(!feof(templateMovie))
        {
            fputc(caracter, nuevaPagina);
            caracter = fgetc(templateMovie);
        }
        fclose(templateMovie);
        fclose(nuevaPagina);
    }
    else if(templateMovie != NULL && nuevaPagina == NULL)
    {
        fclose(templateMovie);
    }
    else if(templateMovie == NULL)
    {
        fclose(nuevaPagina);
    }
    return retorno;
}

static void escribirPelicula(FILE* pFile, Movie* pelicula)
{
    char titulo[50];
    char genero[30];
    int duracion;
    char descripcion[256];
    int puntaje;
    char linkImg[256];

    movie_getTitulo(pelicula, titulo);
    movie_getGenero(pelicula, genero);
    movie_getDuracion(pelicula, &duracion);
    movie_getDescripcion(pelicula, descripcion);
    movie_getPuntaje(pelicula, &puntaje);
    movie_getLinkImagen(pelicula, linkImg);

    fprintf(pFile, "<article class='col-md-4 article-intro'>\n");
    fprintf(pFile, "\t<a href='#'>\n");
    fprintf(pFile, "\t\t<img class='img-responsive img-rounded' src='%s' alt=''>\n", linkImg);
    fprintf(pFile, "\t</a>\n");
    fprintf(pFile, "\t<h3>\n");
    fprintf(pFile, "\t\t<a href='#'>%s</a>\n", titulo);
    fprintf(pFile, "\t</h3>\n");
    fprintf(pFile, "\t<ul>\n");
    fprintf(pFile, "\t\t<li>G&eacutenero:%s</li>\n", genero);
    fprintf(pFile, "\t\t<li>Puntaje:%d</li>\n", puntaje);
    fprintf(pFile, "\t\t<li>Duraci&oacuten:%d</li>\n", duracion);
    fprintf(pFile, "\t</ul>\n");
    fprintf(pFile, "\t<p>%s</p>\n", descripcion);
    fprintf(pFile, "</article>\n");
}
