/*
 * main.c
 *
 *  Created on: 24/4/2015
 *      Author: root
 */
#define PAUSE()  do { printf("\n\n--PAUSE- file: %s line:%d\n", __FILE__, __LINE__); getchar(); } while (0)
#define LIMITE_EMPLEADO 10000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


int main(void)
{
	__fpurge(stdin);
	PAUSE();
	return 0;

}
