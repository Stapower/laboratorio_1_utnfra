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
#include "ListaProductos.h"


int main(void){
	int i;
	char auxStr[20];
	list* pList;
	pList = new_List();

	for(i=0;i<30;i++)
	{
		sprintf(auxStr,"Elemento %d",i);
		pList->append(pList,new_Producto(13,auxStr,22.12,345));
		printf("SIZE: %4d\tRESERVED: %4d\n",pList->size,pList->reservedSize);
	}


	Producto* auxProducto;

	for(i=0;i<pList->size;i++)
	{
		auxProducto = pList->get(pList,i);
		printf("--- %s\n",auxProducto->descripcion);
	}

	auxProducto = pList->pop(pList,15);

	for(i=0;i < pList->size;i++)
	{
			auxProducto = pList->get(pList,i);
			printf("R --- %s\n",auxProducto->descripcion);
	}


	Producto* productos[10]; //declaro un array de punteros a Producto

	/*
	productos[0]= new_Producto(13,"Ladrillo",22.12,345);
	productos[1]= new_Producto(10,"Arandela",22.12,876);
	productos[2]= new_Producto(90,"Tornillo",22.12,21);
	productos[3]= new_Producto(1,"AAAA",22.12,100);
	productos[4]= new_Producto(13,"Ladrillo",22.12,110);
	productos[5]= new_Producto(10,"Arandela",22.12,100);
	productos[6]= new_Producto(90,"Prueba Lista",22.12,34);
	productos[7]= new_Producto(1,"BBB",22.12,100);
	*/

	//printf("%s\n",productos[0]->descripcion);
	//printf("%s\n",productos[5]->descripcion);

	leerListaDesdeArchivo("datos.dat",productos);

	//mostrarProductos(CANTIDAD,productos);



	//guardarListaEnArchivo("datos.dat",productos,7);


	//printf("\nORDENO\n");
	ordenarProductos(7,productos);

	printf("\nMUESTRO\n");
	mostrarProductos(7,productos);

return 0;
}
