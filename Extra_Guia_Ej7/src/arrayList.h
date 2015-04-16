
#define INCREMENT_SIZE 5
#define NULL 0

typedef struct
{
	int reservedSize; 	// Tamaño reservado
	int size;			// Tamaño de la lista
	void ** p_elements;	//Puntero a los elementos de la lista

}list;

list* newList(void);
void append(list* p_list, void* element);
int resizeUp(list* p_list);
