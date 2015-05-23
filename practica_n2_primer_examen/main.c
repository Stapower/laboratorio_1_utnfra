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



int main(void){

	Producto productos[10];

	inicializarProductos(CANTIDAD,productos);
	//mostrarProductos(CANTIDAD,productos);

/*
	productos[0]= new_Producto(13,"Ladrillo",22.12,345);
	productos[1]= new_Producto(10,"Arandela",22.12,876);
	productos[2]= new_Producto(90,"Tornillo",22.12,21);
	productos[3]= new_Producto(1,"AAAA",22.12,100);
	productos[4]= new_Producto(13,"Ladrillo",22.12,110);
	productos[5]= new_Producto(10,"Arandela",22.12,100);
	productos[6]= new_Producto(90,"Tornillo",22.12,34);
	productos[7]= new_Producto(1,"BBB",22.12,100);
*/
	leerListaDesdeArchivo("datos.dat",productos);
	//mostrarProductos(CANTIDAD,productos);


	productos[8]= new_Producto(1,"NUEVO",22.12,100);
	guardarListaEnArchivo("datos.dat",productos,8);

	//leerListaDesdeArchivo("datos.dat",productos);

	printf("\nORDENO\n");
	ordenarProductos(CANTIDAD,productos);
	printf("\nMUESTRO\n");

	mostrarProductos(CANTIDAD,productos);

return 0;
}
