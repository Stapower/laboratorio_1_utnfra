/*
 * Producto.c
 *
 *  Created on: 23/5/2015
 *      Author: root
 */

#include "Producto.h"
#include <stdio.h>
#include <string.h>

Producto* new_Producto(int codigo,char descripcion[],float importe,int cantidad)
{
	Producto* p_auxiliar; // declaro un puntero del tipo producto

	p_auxiliar = (Producto*) malloc(sizeof(Producto));


	p_auxiliar->codigo = codigo;
	p_auxiliar->cantidad = cantidad;
	strcpy(p_auxiliar->descripcion,descripcion);
	p_auxiliar->importe = importe;

	return p_auxiliar;
}
