/*
 * main.c
 *
 *  Created on: 24/4/2015
 *      Author: root
 */
#define PAUSE()  do { printf("\n\n--PAUSE- file: %s line:%d\n", __FILE__, __LINE__); getchar(); } while (0)
#define LIMITE_EMPLEADO 10000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


int main(void)
{
	char pregunta='0';
	int proximo_legajo=1;

	int legajo[LIMITE_EMPLEADO];

	char nombre[LIMITE_EMPLEADO][51];
	char apellido[LIMITE_EMPLEADO][51];
	float salario[LIMITE_EMPLEADO];
	char fecha[LIMITE_EMPLEADO][10];
	char sector[LIMITE_EMPLEADO];

	int pregunta_legajo;

	int i;
	for(i=0;i<LIMITE_EMPLEADO;i++)
	{
		legajo[i]=-1;
	}


    while(pregunta!='9')
    {
    	printf("\n1-ALTA\n");
    	printf("2-EDITAR\n");
    	printf("3-BAJA\n");
    	printf("4-LISTAR\n");
    	printf("9-SALIR\n");
    	scanf("%c",&pregunta);
    	switch(pregunta)
    	{
    	case '1':
    		alta_modifica(proximo_legajo,legajo,nombre,apellido,salario,fecha,sector);
    		break;

    	case '2':
        	printf("\nLegajo a editar:");
        	scanf("%d",&pregunta_legajo);
    		if(existe_legajo(pregunta_legajo, legajo, LIMITE_EMPLEADO)==1)
    		{
    			printf("\nExiste");
    			alta_modifica(pregunta_legajo,legajo,nombre,apellido,salario,fecha,sector);


    		}
    		else
    		{
    			printf("\nEl legajo %d no existe",pregunta_legajo);
    		}

    		break;
    	case '3':
        	printf("\nLegajo a eliminar:");
        	scanf("%d",&pregunta_legajo);
    		if(existe_legajo(pregunta_legajo, legajo, LIMITE_EMPLEADO)==1)
    		{

    			printf("\nExiste");
    			legajo[pregunta_legajo]=-1;

    		}
    		else
    		{
    			printf("\nEl legajo %d no existe",pregunta_legajo);
    		}

    		break;
    		break;
    	case '4':
    		listar(LIMITE_EMPLEADO, legajo,nombre,apellido,salario,fecha,sector);
    		break;


    	case '5':
    		printf("\nGUARDADO\n");

    		break;

    	}

    }

	PAUSE();
	return 0;

}
