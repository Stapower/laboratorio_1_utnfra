#include "List.h"
#include <stdio.h>

// Funciones privadas
void contract(List* p_List, int index);
void expand(List* p_List, int index);
int resizeUp(List *p_List);
// Funciones privadas

List* newList(void)
{

	List* auxList;
	auxList = (List*) malloc(sizeof(List));
	auxList->size = 0;
	auxList->reservedSize = 0;
	auxList->pElements = NULL;

	auxList->append = append; // referencio a la funcion append
	auxList->get = get; // referencio a la funcion get
	auxList->pop = pop; // referencio a la funcion pop
	auxList->put = put;
	auxList->push = push;
	return auxList;

}

void* get(List* p_List,int index)
{
	if (p_List->size > index)
	{
		return p_List->pElements[index];
	}
	return NULL;
}

void append(List* p_List, void* element)
{
	if (p_List->size == p_List->reservedSize)
	{
		resizeUp(p_List);
	}
	p_List->pElements[p_List->size] = element;
	p_List->size++;
}

void push(List* p_List,int index, void* element)
{// Desplaza los elementos e inserta en la posicion index
	if (p_List->size == p_List->reservedSize)
	{
		resizeUp(p_List);
	}
	expand(p_List, index);
	p_List->pElements[index] = element;
	p_List->size++;
}

void* pop(List* p_List,int index)
{ // Elimina de la lista el elemento index y retorna su referencia
	void* returnAux;
	if (p_List->size > index)
	{
		returnAux = p_List->pElements[index];
		contract(p_List, index);
		p_List->size--;
		return returnAux;
	}
	return NULL;
}

int put(List* p_List,int index,void* element)
{ // Pisa el elemento que esta en index

	if (p_List->size > index)
	{
		p_List->pElements[index]=element;
		return 1;
	}
	return 0;
}


void contract(List* p_List, int index)
{ // Contrae la lista eliminando la posicion index
	int i;

	for(i = index ; i < p_List->size - 1 ; i++)
	{
		p_List->pElements[i] = p_List->pElements[i+1];

	}
	p_List->pElements[p_List->size - 1] = NULL;

}

void expand(List* p_List, int index)
{ // Expande la lista generando un espacio vacio en el index
	int i;

	for(i = p_List->size - 1 ; i >= index ; i--)
	{
		p_List->pElements[i+1] = p_List->pElements[i];

	}
	p_List->pElements[index] = NULL;

}

int resizeUp(List *p_List)
{
	/* Redimensionamos el puntero */
	int newSize;

	newSize = sizeof(void*) * (p_List->reservedSize + INCREMENT_SIZE);

	void *tmp_ptr = realloc(p_List->pElements, newSize);

	if (tmp_ptr == NULL) {
		/* Error: tomar medidas necesarias */
		return 0;
	}
	else {
		/* Reasignación exitosa. Asignar memoria a ptr */
		p_List->reservedSize = p_List->reservedSize + INCREMENT_SIZE;
		p_List->pElements = tmp_ptr;
		return 1;
	}

}
