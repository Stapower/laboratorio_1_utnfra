#include "lib.h"
#include <string.h>
#include <stdio.h>
#include "List.h"


void mostrarProductos(List* pList)
{
	int i;
	Producto* auxProducto;
	for(i=0;i < pList->size;i++)
	{
		auxProducto = pList->get(pList,i);
		printf("ID:%d - CANTIDAD:%5d - COD:%5d - DESC:%10s\n",i,auxProducto->cantidad,auxProducto->codigo,auxProducto->descripcion);
	}

}

void ordenarProductos(List* pList)
{
	int i,j;
	Producto* elemento1;
	Producto* elemento2;

	for(i=0;i < pList->size - 1;i++)
	{
		for(j=i+1;j < pList->size;j++)
		{
			elemento1 = pList->get(pList,i);
			elemento2 = pList->get(pList,j);

			if(elemento1->cantidad > elemento2->cantidad)
			{
				pList->put(pList,i,elemento2);
				pList->put(pList,j,elemento1);
			}

		}
	}

}

/*leer Lista desde archivo*/
void leerListaDesdeArchivo(char* nombreArchivo, List* pList)
{


	FILE* f = fopen(nombreArchivo,"rb");
	Producto auxProducto;

	if (f!=NULL)
	{
		while(!feof(f))
		{
			fread(&auxProducto,sizeof(Producto),1,f);
			pList->append(pList,newProducto(auxProducto.codigo,auxProducto.descripcion,auxProducto.importe,auxProducto.cantidad));

		}
	}
	else
	{
		printf( "Error al abrir el archivo \n" );

	}
	fclose(f);
}

/*leer Lista desde archivo*/
void guardarListaEnArchivo(char* nombreArchivo, List* pList)
{
	FILE* f=fopen(nombreArchivo,"wb");
	int indice=0;

	if (f!=NULL)
	{
		for(indice=0;indice<pList->size ;indice++)
		{
			fwrite(pList->get(pList,indice),sizeof(Producto),1,f);
		}
	}
	else
	{
		printf( "Error al abrir el archivo \n" );

	}
	fclose(f);
}


