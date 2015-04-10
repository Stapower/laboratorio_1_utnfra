/*
 ============================================================================
 Name        : Guia_Ej19.c
 Author      : Mauricio
 Version     :
 Copyright   : GLP
 Description :

 En una tienda de artículos para caballeros al final del día se carga en la
 computadora las boletas que confeccionaron los distintos vendedores para
 saber cuanto fue la comisión del día de cada uno de ellos.
 Los datos que se ingresan (por boleta) son: el número de vendedor y el
 importe. Cuando no hay más boletas para cargar se ingresa 0.
 Teniendo en cuenta que el negocio tiene 3 vendedores y que el porcentaje
 sobre las ventas es del 5%, indicar cuánto ganó cada vendedor en el día

 Notas:

 Se puede revalorizar con el concepto de vectores
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PAUSE()  do { printf("\n\n-PAUSE- file: %s line:%d\n", __FILE__, __LINE__); getchar(); } while (0)

int main(void) {

	float ventasVendedor1=0,ventasVendedor2=0,ventasVendedor3=0;
	int numeroVendedor;
	float importe;
	int continuar = 1;
	while(continuar)
	{
		printf("\nIngrese el numero de vendedor: ");
		scanf("%d",&numeroVendedor);

		printf("\nIngrese importe: ");
		scanf("%f",&importe);

		switch(numeroVendedor)
		{
			case 1:
				ventasVendedor1 += importe;
				break;
			case 2:
				ventasVendedor2 += importe;
				break;
			case 3:
				ventasVendedor3 += importe;
				break;

			default:
				printf("El vendedor %d no existe", numeroVendedor);
				break;

		} // switch



		printf("\nPara salir pulse 0 - ");
		fflush(stdin);
		scanf("%d",&continuar);
		fflush(stdin);
	} // while

	printf("\nVendedor 1 - Comision: %.2f", ventasVendedor1 * 0.05);
	printf("\nVendedor 2 - Comision: %.2f", ventasVendedor2 * 0.05);
	printf("\nVendedor 3 - Comision: %.2f", ventasVendedor3 * 0.05);

	PAUSE();
	return EXIT_SUCCESS;


}



