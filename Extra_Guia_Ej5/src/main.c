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
#include "mylib.h"


#define PAUSE()  do { printf("\n\n-PAUSE- file: %s line:%d\n", __FILE__, __LINE__); getchar(); } while (0)

#define ARRAY_SIZE 100


int main(void)
{

  palabra palabras[ARRAY_SIZE];
  char cadena[50];


  inicializarArray(palabras, ARRAY_SIZE);

  FILE *f = fopen("/home/mauricio/git/laboratorio_1_utnfra/Extra_Guia_Ej5/src/archivo.txt", "r");
  if (f==NULL)
  {
     perror ("Error al abrir archivo.txt");
     return -1;
  }

  while (fscanf (f, "%[a-zA-Z]%*[^a-zA-Z]", cadena) != EOF )
  {
	  contarPalabra(palabras, ARRAY_SIZE, cadena );
  }

  ordenarArray(palabras, ARRAY_SIZE);
  mostrarResultado(palabras, ARRAY_SIZE);

  PAUSE();
  return 1;
}






