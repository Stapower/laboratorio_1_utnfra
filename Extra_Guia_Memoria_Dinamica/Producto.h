/*
 * Producto.h
 *
 *  Created on: 23/5/2015
 *      Author: root
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct
{
	int codigo;
	char descripcion[51];
	float importe;
	int cantidad;
}Producto;


Producto* new_Producto(int codigo,char descripcion[],float importe,int cantidad);


#endif /* PRODUCTO_H_ */
