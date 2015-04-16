/*
 ============================================================================
 Name        : Extra_Guia_Ej7.c
 Author      : 
 Version     :
 Copyright   : GLP
 Description : Leer un archivo y dejar su contenido en un char array
 ============================================================================
 */
#define PAUSE()  do { printf("\n\n-PAUSE- file: %s line:%d\n", __FILE__, __LINE__); getchar(); } while (0)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"


int main(void)
{

  char contenidoArchivo[1024];

  leerArchivo("/home/mauricio/git/laboratorio_1_utnfra/Extra_Guia_Ej7/src/archivo.txt",contenidoArchivo);
  printf("%s",contenidoArchivo);

  PAUSE();
  return 1;
}





