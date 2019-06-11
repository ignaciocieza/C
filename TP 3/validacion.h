#ifndef validacion_H_INCLUDED
#define validacion_H_INCLUDED
#include "validacion.h"
#include "funciones.h"



int getInt(char* mensaje);
float getFloat(char* mensaje);
char getChar(char* mensaje);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

int getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidStringLetras(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);

void clearStdin(void);
void pause(void);
void clearScreen(void);

int movie_setId(Movie* this);
int movie_setIsEmpty(Movie* this, int isEmpty);
int movie_setTitulo(Movie* this);
int movie_setGenero(Movie* this);
int movie_setDescripcion(Movie* this);
int movie_setDuracion(Movie* this);
int movie_setPuntaje(Movie* this);
int movie_setLinkImagen(Movie* this);

int movie_getLinkImagen(Movie* this, char* linkImg);
int movie_getId(Movie* this, int* id);
int movie_getIsEmpty(Movie* this, int* isEmpty);
int movie_getTitulo(Movie* this, char* titulo);
int movie_getGenero(Movie* this, char* genero);
int movie_getDescripcion(Movie* this, char* descripcion);
int movie_getPuntaje(Movie* this, int* puntaje);
int movie_getDuracion(Movie* this, int* duracion);

void movie_delete(Movie* this);

#endif // validacion_H_INCLUDED
