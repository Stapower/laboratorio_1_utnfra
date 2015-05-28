/*
 * Dict.h
 *
 *  Created on: 23/5/2015
 *      Author: root
 */

#ifndef Dict_H_
#define Dict_H_

#define INITIAL_SIZE (1024)
#define GROWTH_FACTOR (2)
#define MAX_LOAD_FACTOR (1)
#define MULTIPLIER (97)




typedef struct elt
{

    char *key;
    char *value;
    struct elt *next;

}Element;

typedef struct
{
    int size;           /* size of the pointer table */
    int n;              /* number of elements stored */
    Element **table;

	void (* insert)(); // funcion insert Key Value
	void (* remove)(); // funcion remove from Key
	void* (* get)(); // funcion get

}Dict;


Dict* newDict(int size);

void insertDict(Dict* d, const char *key, const char *value);
const char * getDict (Dict* d, const char *key);
Element* getElement(Dict* d, const char *key);
unsigned long hash(const char* pText,int maxValue);

#endif /* Dict_H_ */

