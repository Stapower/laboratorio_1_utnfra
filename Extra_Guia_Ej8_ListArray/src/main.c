/*
 ============================================================================
 Name        : Test_C.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "arrayList.h"

int main(void) {

	int i, a=10;


	list* auxiliar = newList();


	for(i = 0; i<50;i++)
	{
		append(auxiliar,&a);
		printf("SIZE: %4d\tRESERVED: %4d\n",auxiliar->size,auxiliar->reservedSize);

	}

	scanf("%*c");

	return EXIT_SUCCESS;

}



