typedef struct
{
	char texto[50];
	int cantidad;
}palabra;

int contarPalabra(palabra * auxPalabras, int size_array,char * cadena);
void inicializarArray(palabra * auxPalabras, int size_array);
void mostrarResultado(palabra * auxPalabras, int size_array);
void ordenarArray(palabra * auxPalabras, int size_array);


