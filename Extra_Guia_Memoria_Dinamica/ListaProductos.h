/*
 * ListaProductos.h
 *
 *  Created on: 23/5/2015
 *      Author: root
 */
#include "Producto.h"

#ifndef LISTAPRODUCTOS_H_
#define LISTAPRODUCTOS_H_


#define INCREMENT_SIZE 5


typedef struct
{
	int reservedSize; 	// Tamaño reservado
	int size;			// Tamaño de la lista
	void ** p_elements;	//Puntero a los elementos de la lista

	void (* append)(); // funcion append
	void* (* get)(); // funcion get
}list;


list* new_List(void);
void append(list* p_list, void* element);
void* get(list* p_list,int index);
int resizeUp(list* p_list);





#endif /* LISTAPRODUCTOS_H_ */

