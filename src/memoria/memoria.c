#include "memoria.h"
#include "../errores/errores.h"


void guardar_ram (int i, memoria_ram *memoria, char *nombre, int data)
{
	if (i < 0)

	/* enteros de 4 bytes */
	if(i >= LIMITE_MEMORIA/4)
	{
		tirar_error(MEMORIA_AGOTADA);
	}
		
	strcpy(memoria->celdas[i].nombre, nombre);
	memoria->celdas[i].data = data;
	return;
}

int get_index_ram (char *nombre, memoria_ram *memoria)
{
	for (int i = 0; i < LIMITE_MEMORIA; i++)
		if (!strcmp(nombre, memoria->celdas[i].nombre))
			return i;
	
	// Si no coincide muestra error
	printf("Undefined reference : %s", nombre);
}

memoria_ram *init_ram (int lim) 
{

	memoria_ram *ram = calloc(sizeof(memoria_ram), 1);
	ram->limite = lim;
	ram->elementos = 0;
	ram->rows = calloc(sizeof(row), (lim < 1) ? LIMITE_MEMORIA_DEFAULT : lim);
}
