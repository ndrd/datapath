#include "memoria.h"
#include "../errores/errores.h"


void guardar_ram (int i, memoria_ram *memoria, int data)
{
	if (i < 0)
		return;

	 //enteros de 4 bytes 
	if(i >= memoria->limite/4)
	{
		tirar_error(MEMORIA_AGOTADA);
	}
		
	memoria->rows[i].data = data;
	memoria->elementos++;
	return;
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
