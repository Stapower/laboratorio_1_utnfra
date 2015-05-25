
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
#include "Lista.h"


int main(void){
	int i;
	char auxStr[20];
	list* pList;
	Producto* auxProducto;


	pList = new_List();

	for(i=0;i<30;i++)
	{
		sprintf(auxStr,"Elemento %d",i);
		pList->append(pList,new_Producto(13,auxStr,22.12,345));
		printf("SIZE: %4d\tRESERVED: %4d\n",pList->size,pList->reservedSize);
	}

	pList->put(pList,11,new_Producto(13,"Prueba put",22.12,345));


	mostrarProductos(pList);

	auxProducto = pList->pop(pList,15);

	printf("\n--- Resultado ---\n");
	mostrarProductos(pList);

/*
	leerListaDesdeArchivo("datos.dat",pList);

	guardarListaEnArchivo("datos.dat",pList);

	ordenarProductos(pList);

	mostrarProductos(pList);
*/

return 0;
}
