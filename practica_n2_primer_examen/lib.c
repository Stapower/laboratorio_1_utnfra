#include "lib.h"
#include <string.h>
#include <stdio.h>

Producto new_Producto(int codigo,char descripcion[],float importe,int cantidad)
{
	Producto auxiliar;
	auxiliar.codigo = codigo;
	auxiliar.cantidad = cantidad;
	strcpy(auxiliar.descripcion,descripcion);
	auxiliar.importe = importe;
	return auxiliar;
}

void inicializarProductos(int cantidad,Producto productos[])
{
	int i;
	for(i=0;i<cantidad;i++)
	{
		productos[i].codigo = -1;

	}

}

void mostrarProductos(int cantidad,Producto productos[])
{
	int i;
	for(i=0;i<cantidad;i++)
	{
		if(productos[i].codigo>0)
		{
			printf("CANTIDAD:%5d - COD:%5d - DESC:%10s\n",productos[i].cantidad,productos[i].codigo,productos[i].descripcion);
		}
	}

}

void ordenarProductos(int cantidad,Producto productos[])
{
	int i,j;
	Producto auxiliar;
	for(i=0;i<cantidad - 1;i++)
	{
		for(j=i+1;j<cantidad;j++)
		{

			if(productos[i].cantidad > productos[j].cantidad)
			{
				auxiliar = productos[i];
				productos[i]=productos[j];
				productos[j]=auxiliar;
			}
			else if(productos[i].cantidad == productos[j].cantidad)
			{

				if(strcmp(productos[i].descripcion, productos[j].descripcion) == -1)
				{
					auxiliar = productos[i];
					productos[i]=productos[j];
					productos[j]=auxiliar;
				}

			}


		}
	}

}


