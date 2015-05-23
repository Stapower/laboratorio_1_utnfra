/*
 * lib.h
 *
 *  Created on: 24/4/2015
 *      Author: root
 */
#include "tipos.h"

Producto new_Producto(int codigo,char descripcion[],float importe,int cantidad);

void inicializarProductos(int cantidad,Producto productos[]);
void mostrarProductos(int cantidad,Producto productos[]);
void ordenarProductos(int cantidad,Producto productos[]);


void guardarListaEnArchivo(char *nombreArchivo, Producto productos[],int cantidad);
void leerListaDesdeArchivo(char *nombreArchivo, Producto productos[]);
