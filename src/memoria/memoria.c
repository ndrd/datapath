#include "memoria.h"
#include "../errores/errores.h"

/* limite en bytes */
int LIMITE_MEMORIA = 4096;

void guardar_ram(int i, struct memoria_datos *memoria, char *nombre, int data)
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

int get_index_ram(char *nombre, struct memoria_datos *memoria)
{
	for (int i = 0; i < LIMITE_MEMORIA; i++)
		if (!strcmp(nombre, memoria->celdas[i].nombre))
			return i;
	
	// Si no coincide muestra error
	printf("Undefined reference : %s", nombre);
}

void set_lim_mem_ram(int lim) 
{
	LIMITE_MEMORIA = lim;
}
