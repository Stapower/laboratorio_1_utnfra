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

#define ARRAY_SIZE 100

typedef struct
{
	char texto[50];
	int cantidad;
}palabra;

int contarPalabra(palabra * auxPalabras, int size_array,char * cadena);
void inicializarArray(palabra * auxPalabras, int size_array);
void mostrarResultado(palabra * auxPalabras, int size_array);
void ordenarArray(palabra * auxPalabras, int size_array);

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


