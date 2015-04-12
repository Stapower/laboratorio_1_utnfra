/*
 ============================================================================
 Name        : Extra_Guia_Ej5.c
 Author      : 
 Version     :
 Copyright   : GLP
 Description : Contar las palabras de un txt no mas de 100 distintas
 ============================================================================
 */

#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#define PAUSE()  do { printf("\n\n-PAUSE- file: %s line:%d\n", __FILE__, __LINE__); getchar(); } while (0)

#define ARRAY_SIZE 1000

typedef struct
{
	char texto[50];
	int cantidad;
}palabra;

int leerArchivo(char nombre[],char contenido[]);
void mostrarResultado(palabra* auxPalabras, int size_array);
void ordenarArray(palabra* auxPalabras, int size_array);

int main(void)
{

  //palabra palabras[ARRAY_SIZE];
  //char cadena[50];
  char contenidoArchivo[1024];

  leerArchivo("/home/mauricio/workspace_c/Extra_Guia_Ej7/src/archivo.txt",contenidoArchivo);
  printf("%s",contenidoArchivo);

  PAUSE();
  return 1;
}

int leerArchivo(char nombre[],char contenido[])
{
	FILE *f;
	char aux_cadena[100];
	contenido[0] = '\0';

	f = fopen(nombre, "r");

	if (f==NULL)
	{
	   return -1;
	}

	while (fscanf (f, "%c", aux_cadena) != EOF )
	{
		  strcat(contenido,aux_cadena);
	}
	fscanf (f, "%s", contenido);

	return 1;
}


void mostrarResultado(palabra auxPalabras[], int size_array)
{

}

void inicializarArray(palabra * auxPalabras, int size_array)
{

}

void ordenarArray(palabra * auxPalabras, int size_array)
{

}




