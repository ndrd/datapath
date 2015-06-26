#include "memoria.h"
#include "../errores/errores.h"


void guardar_ram (int i, memoria_ram *memoria, char *nombre, int data)
{
	if (i < 0)
		return;

	printf("%d\n", memoria->limite/4);

	/* enteros de 4 bytes */
	if(i >= memoria->limite/4)
	{
		tirar_error(MEMORIA_AGOTADA);
	}
		
	strcpy(memoria->rows[i].nombre, nombre);
	memoria->rows[i].data = data;
	memoria->elementos++;
	return;
}

int get_index_ram (char *nombre, memoria_ram *memoria)
{
	if (memoria == NULL || nombre ==  NULL)
		return -1;

	for (int i = 0; i < memoria->limite; i++) {
		printf("%s\n", memoria->rows[i].nombre);
		if (!strcmp(nombre, memoria->rows[i].nombre))
			return i;
	}
	
	// Si no coincide muestra error
	printf("Undefined reference : %s", nombre);
}

/* Inicializa una memoria ram de un tamanio dado en bytes */
memoria_ram* 
init_ram (int lim_bytes) 
{
	/* cada celda almacena 4 bytes (unsigned int) */
	int lim = lim_bytes/4;

	memoria_ram *ram = calloc(sizeof(memoria_ram), 1);
	ram->limite = lim;
	ram->elementos = 0;
	ram->rows = calloc((lim < 1) ? LIMITE_MEMORIA_DEFAULT : lim, sizeof(row)	);
	return ram;
}
