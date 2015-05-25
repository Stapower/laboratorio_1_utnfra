/*
 * lib.h
 *
 *  Created on: 24/4/2015
 *      Author: root
 */
#include "Lista.h"
#include "Producto.h"


void mostrarProductos(list* pList);

void ordenarProductos(list* pList);


void guardarListaEnArchivo(char* nombreArchivo, list* pList);
void leerListaDesdeArchivo(char* nombreArchivo, list* pList);
