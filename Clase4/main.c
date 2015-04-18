/*
 * main.c
 *
 *  Created on: 17/4/2015
 *      Author: root
 */

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"


int main(void)
{

	char nombres[size_array][50];
	int i;

	for (i=0;i<size_array;i++)
	{

		printf("Ingrese Nombre_:");
		scanf("%s",nombres[i]);
	}

	ordena(nombres);

	return 1;
}

