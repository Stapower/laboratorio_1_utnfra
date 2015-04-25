/*
 * lib.c
 *
 *  Created on: 24/4/2015
 *      Author: root
 */

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alta_modifica(int proximo_legajo,int legajo[],char nombre[][51],char apellido[][51],float salario[],char fecha[][10],char sector[])
{
	legajo[proximo_legajo] = proximo_legajo;

	/*CONSULTAR*/
	printf("\nNOMBRE:");
	scanf("%s",nombre[proximo_legajo]);

	printf("\nAPELLIDO:");
	scanf("%s",apellido[proximo_legajo]);

	printf("\nSALARIO:");
	scanf("%f",&salario[proximo_legajo]);
	fflush(stdin);

	printf("\nSECTOR:");
	scanf("%d",&sector[proximo_legajo]);
	fflush(stdin);

	printf("\nFECHA:");
	scanf("%s",fecha[proximo_legajo]);
}

void listar(int limite, int legajo[],char nombre[][51],char apellido[][51],float salario[],char fecha[][10],char sector[])
{

	int i;
	for(i=0;i < limite;i++)
	{
		if(legajo[i] != -1)
			printf("\n%10d %20s %20s",legajo[i],nombre[i],apellido[i]);

	}


}


int existe_legajo(int pregunta_legajo, int legajo[], int limite)
{

	int i;
	for(i=0;i < limite;i++)
	{
		if(legajo[i] == pregunta_legajo)
		{
			return 1;
		}

	}
	return 0;


}



