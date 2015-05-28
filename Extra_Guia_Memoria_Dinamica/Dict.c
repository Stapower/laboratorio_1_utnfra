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

    for(i = 0; i < auxDict->size; i++)
    	auxDict->table[i] = NULL;

    return auxDict;

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

    auxElement = (Element*)malloc(sizeof(Element));

    auxElement->key = strdup(key);
    auxElement->value = strdup(value);

    h = hash(key,d->size);

    auxElement->next = d->table[h];
    d->table[h] = auxElement;

    d->n++;

    /*

    if(d->n >= d->size * MAX_LOAD_FACTOR) {
        grow(d);
    }

    */
}

const char* getDict(Dict* d, const char *key)
{
   Element *auxElement;

   auxElement = d->table[hash(key,d->size)];

   while(auxElement != NULL)
   {
		if(strcmp(auxElement->key, key) == 0)
		{
			return auxElement->value;
		}
		auxElement = auxElement->next;
   }
   return 0;
}

