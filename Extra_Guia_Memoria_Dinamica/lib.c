#include "lib.h"
#include <string.h>
#include <stdio.h>


void mostrarProductos(int cantidad,Producto* productos[])
{
	int i;
	for(i=0;i<cantidad;i++)
	{
		if(productos[i]->codigo>0)
		{
			printf("CANTIDAD:%5d - COD:%5d - DESC:%10s\n",productos[i]->cantidad,productos[i]->codigo,productos[i]->descripcion);
		}
	}

}

void ordenarProductos(int cantidad,Producto* productos[])
{
	int i,j;
	Producto* auxiliar;

	for(i=0;i < cantidad - 1;i++)
	{
		for(j=i+1;j < cantidad;j++)
		{

			if(productos[i]->cantidad > productos[j]->cantidad)
			{
				auxiliar = productos[i];
				productos[i]=productos[j];
				productos[j]=auxiliar;
			}
			else if(productos[i]->cantidad == productos[j]->cantidad)
			{

				if(strcmp(productos[i]->descripcion, productos[j]->descripcion) == -1)
				{
					auxiliar = productos[i];
					productos[i]=productos[j];
					productos[j]=auxiliar;
				}

			}


		}
	}

}

/*leer lista desde archivo*/
void leerListaDesdeArchivo(char* nombreArchivo, Producto* productos[])
{


	FILE* f = fopen(nombreArchivo,"rb");
	Producto auxProducto;

	int indice=0;


	if (f!=NULL)
	{
		while(!feof(f))
		{
			fread(&auxProducto,sizeof(Producto),1,f);
		 	productos[indice] = new_Producto(auxProducto.codigo,auxProducto.descripcion,auxProducto.importe,auxProducto.cantidad);
			indice++;
		}
	}
	else
	{
		printf( "Error al abrir el archivo \n" );

	}
	fclose(f);
}

/*leer lista desde archivo*/
void guardarListaEnArchivo(char *nombreArchivo, Producto* p_productos[],int cantidad)
{
	FILE* f=fopen(nombreArchivo,"wb");
	int indice=0;

	if (f!=NULL)
	{
		for(indice=0;indice<cantidad;indice++)
		{
			fwrite(p_productos[indice],sizeof(Producto),1,f);
		}
	}
	else
	{
		printf( "Error al abrir el archivo \n" );

	}
	fclose(f);
}


