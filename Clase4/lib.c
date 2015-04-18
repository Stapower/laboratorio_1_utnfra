/*
 * lib.c
 *
 *  Created on: 17/4/2015
 *      Author: root
 */

#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ordena(char aux_list[][50])
{
	int i,j;
	char valor_mas_chico[50];
	int pos_mas_chico;

	for (i=0; i < size_array-1;i++)
	{

		strcpy(valor_mas_chico,aux_list[i]);
		pos_mas_chico = i;

		for (j=i+1;j<size_array;j++)
		{
			if(strcmp(valor_mas_chico,aux_list[j]) > 0)
			{
				strcpy(valor_mas_chico,aux_list[j]);
				pos_mas_chico = j;
			}
		}

		if (i != pos_mas_chico)
		{
			strcpy(aux_list[pos_mas_chico],aux_list[i]);
			strcpy(aux_list[i] , valor_mas_chico);
		}

	}



	for (i=0;i<size_array;i++)
	{
		printf("\n%s",aux_list[i]);

	}



}

