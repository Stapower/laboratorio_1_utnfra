/*
 * mylib.c
 *
 *  Created on: 10/4/2015
 *      Author: mauricio
 */
#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

