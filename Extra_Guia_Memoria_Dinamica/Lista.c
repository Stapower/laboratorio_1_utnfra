#include "Lista.h"
#include <stdio.h>



list* new_List(void)
{

	list* auxList;
	auxList = (list*) malloc(sizeof(list));
	auxList->size = 0;
	auxList->reservedSize = 0;
	auxList->p_elements = NULL;

	auxList->append = append; // referencio a la funcion append
	auxList->get = get; // referencio a la funcion get
	auxList->pop = pop; // referencio a la funcion pop
	auxList->put = put;
	return auxList;

}

void* get(list* p_list,int index)
{
	if (p_list->size > index)
	{
		return p_list->p_elements[index];
	}
	return NULL;
}

void append(list* p_list, void* element)
{
	if (p_list->size == p_list->reservedSize)
	{
		resizeUp(p_list);
	}
	p_list->p_elements[p_list->size] = element;
	p_list->size++;
}

void* pop(list* p_list,int index)
{
	void* returnAux;
	if (p_list->size > index)
	{
		returnAux = p_list->p_elements[index];
		p_list->p_elements[index] = NULL;
		compact(p_list); // Compacto la lista
		return returnAux;
	}
	return NULL;
}

int put(list* p_list,int index,void* element)
{

	if (p_list->size > index)
	{
		p_list->p_elements[index]=element;
		return 1;
	}
	return 0;
}


void compact(list* p_list)
{
	int i,j;

	for(i=0;i<p_list->size - 1;i++)
	{
		for(j=i;j<p_list->size;j++)
		{
			if (p_list->p_elements[i] == NULL && p_list->p_elements[j] != NULL)
				{
					p_list->p_elements[i] = p_list->p_elements[j];
					p_list->p_elements[j] = NULL;

				}
		}
	}
	p_list->size--;

}


int resizeUp(list *p_list)
{
	/* Redimensionamos el puntero */
	int newSize;

	newSize = sizeof(void*) * (p_list->reservedSize + INCREMENT_SIZE);

	void *tmp_ptr = realloc(p_list->p_elements, newSize);

	if (tmp_ptr == NULL) {
		/* Error: tomar medidas necesarias */
		return 0;
	}
	else {
		/* Reasignación exitosa. Asignar memoria a ptr */
		p_list->reservedSize = p_list->reservedSize + INCREMENT_SIZE;
		p_list->p_elements = tmp_ptr;
		return 1;
	}

}
