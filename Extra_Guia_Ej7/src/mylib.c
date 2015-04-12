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



void mostrarResultado(palabra auxPalabras[], int size_array)
{
	int i;
	printf("         PALABRA\tCANTIDAD\n");

	for(i=0; i < size_array;i++)
	  {
		  if (strlen(auxPalabras->texto) > 0)
		  {
			  printf("%-20s\t\t%d\n",auxPalabras->texto,auxPalabras->cantidad);
		  }
		  auxPalabras++;

	  }
}

void inicializarArray(palabra * auxPalabras, int size_array)
{
	int i;

	for(i=0; i < size_array ; i++)
	{
		auxPalabras->cantidad = 0;
		auxPalabras->texto[0] = '\0';
		auxPalabras++;
	}
}

void ordenarArray(palabra * auxPalabras, int size_array)
{
	int i,j;
    palabra auxPalabra;


	for(i=0; i < size_array ; i++)
	{
		for(j=i+1; j < size_array ; j++)
		{
			if(auxPalabras[i].cantidad < auxPalabras[j].cantidad)
			{
				auxPalabra = auxPalabras[i];
				auxPalabras[i] = auxPalabras[j];
				auxPalabras[j] = auxPalabra;
			}
		}
	}

}



int contarPalabra(palabra * auxPalabras, int size_array,char * cadena)
{
	int i;

	for(i=0; i < size_array ; i++)
	{

		if (strcmp(auxPalabras[i].texto, cadena) == 0)
		{
			auxPalabras[i].cantidad++;
			break;
		}
		else if (strlen(auxPalabras[i].texto) == 0)
		{
			strcpy(auxPalabras[i].texto, cadena);
			auxPalabras[i].cantidad++;
			break;
		}
	}
	return 1;

}
