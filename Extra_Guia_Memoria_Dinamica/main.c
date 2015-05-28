
/*
 * main.c
 *
 *  Created on: 24/4/2015
 *      Author: root
 */
#define PAUSE()  do { printf("\n\n--PAUSE- file: %s line:%d\n", __FILE__, __LINE__); getchar(); } while (0)
#define CANTIDAD 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "Producto.h"
#include "List.h"
#include "Dict.h"

int main(void){
	int i;
	char auxStr[20];
	char auxStr2[20];
	List* pList;
	Producto* auxProducto;
	Dict* pDict;


	pDict = newDict(10);

	for(i = 0; i<100; i++)
	{
		sprintf(auxStr,"Clave %d",i);
		sprintf(auxStr2,"Valor %d",i);
		pDict->insert(pDict,auxStr,auxStr);
	}
	//pDict->insert(pDict,"Hola","Mundo 1");
	//pDict->insert(pDict,"olHadao","Mundo 3");
	//pDict->insert(pDict,"Hola","Mundo 10");

	pDict->remove(pDict, "Clave 10");

	for(i = 0; i<100; i++)
	{
		sprintf(auxStr,"Clave %d",i);
		printf("Valor del dicc %s\n",pDict->get(pDict,auxStr));
	}


	//printf("Valor del dicc %s\n",pDict->get(pDict,"Clave 14"));
	//printf("Valor del dicc %s\n",pDict->get(pDict,"Clave 99"));


	pList = newList();

	for(i=0;i<30;i++)
	{
		sprintf(auxStr,"Elemento %d",i);
		pList->append(pList,newProducto(13,auxStr,22.12,345));
		printf("SIZE: %4d\tRESERVED: %4d\n",pList->size,pList->reservedSize);
	}

	pList->push(pList,10,newProducto(13,"Prueba push",22.12,345));
	pList->push(pList,12,newProducto(13,"Prueba push",22.12,345));
	pList->push(pList,14,newProducto(13,"Prueba push",22.12,345));
	mostrarProductos(pList);


	auxProducto = pList->pop(pList,10);
	auxProducto = pList->pop(pList,11);
	auxProducto = pList->pop(pList,12);
	mostrarProductos(pList);

	//auxProducto = pList->pop(pList,15);
	/*
	printf("\n--- Resultado ---\n");
	mostrarProductos(pList);


	leerListaDesdeArchivo("datos.dat",pList);

	guardarListaEnArchivo("datos.dat",pList);

	ordenarProductos(pList);

	mostrarProductos(pList);
*/

return 0;
}
