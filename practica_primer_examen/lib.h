/*
 * lib.h
 *
 *  Created on: 24/4/2015
 *      Author: root
 */

void alta_modifica(int proximo_legajo,int legajo[],char nombre[][51],char apellido[][51],float salario[],char fecha[][10],char sector[]);
void listar(int limite, int legajo[],char nombre[][51],char apellido[][51],float salario[],char fecha[][10],char sector[]);
int existe_legajo(int pregunta_legajo, int legajo[], int limite);
