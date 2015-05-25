/*
 * lib.h
 *
 *  Created on: 24/4/2015
 *      Author: root
 */
#include "List.h"
#include "Producto.h"


void mostrarProductos(List* pList);

void ordenarProductos(List* pList);


void guardarListaEnArchivo(char* nombreArchivo, List* pList);
void leerListaDesdeArchivo(char* nombreArchivo, List* pList);
