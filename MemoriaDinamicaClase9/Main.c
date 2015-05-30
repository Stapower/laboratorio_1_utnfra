#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	//Variables
	int size;
	int* elements;

	//Funciones
	void (*add)();
}ArrayList;

ArrayList* newArrayList();
int get(ArrayList* pArray,int index);
void add(ArrayList* pArray,int aux);
int resizeUp(ArrayList* pArray);

int main(void){
	char resp[2];
	int aux;
	int c;
	ArrayList* pLista;

	pLista = newArrayList();

	do{
		printf("indique un numero\n");
		scanf("%d",&aux);

		//add(pLista,aux);
		pLista->add(pLista,aux);

		printf("quieres agregar otro numero");
		scanf("%s",resp);

	}
	while(strcmp(resp,"s")==0);

	for(c=0;c<pLista->size-1;c++){
		printf("%d\n",get(pLista,c));

	}

	return 1;


}

int get(ArrayList* pArray,int index)
{
	return pArray->elements[index];
}

void add(ArrayList* pArray,int aux)
{
	pArray->elements[pArray->size-1] = aux;
	resizeUp(pArray);
}

int resizeUp(ArrayList* pArray)
{
	void* tmp_ptr;
	tmp_ptr = realloc(pArray->elements,(sizeof(int))*(pArray->size+1));

	if (tmp_ptr == NULL) {
		/* Error: tomar medidas necesarias */
		return 0;
	}
	else {
		/* Reasignación exitosa. Asignar memoria a ptr */
		pArray->elements = tmp_ptr;
		pArray->size++;
		return 1;
	}
}

ArrayList* newArrayList()
{// Constructor
	ArrayList* pAuxArrayList;
	pAuxArrayList = (ArrayList*) malloc(sizeof(ArrayList));

	pAuxArrayList->elements =(int*)malloc(sizeof(int));
	pAuxArrayList->size=1;

	pAuxArrayList->add = add;

	return pAuxArrayList;

}
