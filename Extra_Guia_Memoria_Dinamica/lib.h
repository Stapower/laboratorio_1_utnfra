/*
 * lib.h
 *
 *  Created on: 24/4/2015
 *      Author: root
 */
#include "Producto.h"
#include "ListaProductos.h"


void mostrarProductos(int cantidad,Producto* productos[]);
void ordenarProductos(int cantidad,Producto* productos[]);


void guardarListaEnArchivo(char *nombreArchivo, Producto* productos[],int cantidad);
void leerListaDesdeArchivo(char *nombreArchivo, Producto* productos[]);
