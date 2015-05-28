/*
 * List.h
 *
 *  Created on: 23/5/2015
 *      Author: root
 */
#include "Producto.h"

#ifndef ListA_H_
#define ListA_H_


#define INCREMENT_SIZE 5


typedef struct
{
	int reservedSize; 	// Tamaño reservado
	int size;			// Tamaño de la Lista
	void ** pElements;	//Puntero a los elementos de la Lista

	void (* append)(); // funcion append
	void* (* get)(); // funcion get
	void* (* pop)(); // funcion pop
	void* (* put)(); // funcion put
	void* (* push)(); // funcion put

}List;


List* newList(void);

void append(List* p_List, void* element);
void* get(List* p_List,int index);
void* pop(List* p_List,int index);
int put(List* p_List,int index,void* element);
void push(List* p_List,int index,void* element);





#endif /* ListA_H_ */

