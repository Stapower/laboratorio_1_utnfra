#include "Dict.h"
#include <stdio.h>
#include <stddef.h>


// Funciones privadas

// Funciones privadas



Dict* newDict(int size)
{


    Dict* auxDict;
    int i;

    auxDict = (Dict*) malloc(sizeof(Dict));

    auxDict->size = size;
    auxDict->n = 0;
    auxDict->table = malloc(sizeof(Element *) * auxDict->size);
    auxDict->get = getDict;
    auxDict->insert = insertDict;
    auxDict->remove = removeDict;
    for(i = 0; i < auxDict->size; i++)
    	auxDict->table[i] = NULL;

    return auxDict;

}

void removeDict(Dict* d, const char *key)
{
    Element* preAuxElement;          /* Este apunta (si existe al anterior) */
    Element* auxElement;              /* Este apunta al element a eliminar */
    Element* freeElement;
    int index;


    preAuxElement = NULL;

    index = hash(key,d->size);
    auxElement = d->table[index];

    while(auxElement != NULL)
    {
 		if(strcmp(auxElement->key, key) == 0)
 		{


				if(preAuxElement == NULL)
				{

					d->table[index] = auxElement->next;

					free(auxElement->value);
					free(auxElement->key);
					free(auxElement);

				}
				else
				{
					preAuxElement->next = auxElement->next;

					free(auxElement->value);
					free(auxElement->key);
					free(auxElement);

				}
 		}
 		else
 		{

 			preAuxElement = auxElement;
 			auxElement = auxElement->next;
 		}
    }

}

unsigned long hash(const char* pText,int maxValue)
{
	unsigned long auxHash;
	unsigned const char* pUnsignedText;
	pUnsignedText = ( unsigned const char* ) pText;
	auxHash = 0;

	while(*pUnsignedText != '\0') {
		auxHash = auxHash * MULTIPLIER + *pUnsignedText;
		pUnsignedText++;
	}

	auxHash = auxHash % maxValue; //Resto división entera

	//printf("\nHASH: %d\n",auxHash);

	return auxHash;
}


void insertDict(Dict* d, const char *key, const char *value)
{
    Element *auxElement;
    unsigned long h;

    auxElement = getElement(d, key);

    if(auxElement == NULL)
    {

		auxElement = (Element*)malloc(sizeof(Element));

		auxElement->key = strdup(key); // copio el contenio en un nuevo str
		auxElement->value = strdup(value);

		h = hash(key,d->size);

		auxElement->next = d->table[h];
		d->table[h] = auxElement;

		d->n++;

    }
    else
    {
    	free(auxElement->value); //Libero el espacio
    	auxElement->value = strdup(value);

    }
    /*

    if(d->n >= d->size * MAX_LOAD_FACTOR) {
        grow(d);
    }

    */
}

//Obtiene un elemento del diccionario
Element* getElement(Dict* d, const char *key)
{
   Element* auxElement;

   auxElement = d->table[hash(key,d->size)];

   while(auxElement != NULL)
   {
		if(strcmp(auxElement->key, key) == 0)
		{
			return auxElement;
		}
		auxElement = auxElement->next;
   }
   return NULL;
}


const char* getDict(Dict* d, const char *key)
{
   Element *auxElement;

   auxElement = getElement(d, key);

   if(auxElement != NULL)
   {
	   return auxElement->value;
   }
   return 0;
}

