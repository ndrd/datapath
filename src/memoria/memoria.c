#include "memoria.h"

int LIMITE_MEMORIA_REGISTROS = 1024;

void guardar(int i, struct registros *registros, char *nombre, int valor)
{
	if(i >= LIMITE_MEMORIA_REGISTROS)
	{
		printf("No hay suficiente espacio");
		exit(2);				
	}
		
	strcpy(registros->mem[i].nombre,nombre);
	registros->mem[i].valor=valor;
	return;
}

int get_lugar(char*nombre,struct registros *registros)
{
	int i;
	for(i=0; i< LIMITE_MEMORIA_REGISTROS;i++)
	{
		if(!strcmp(nombre,registros->mem[i].nombre))
			return i;
	}
	
	// Si no coincide muestra error
	printf("Undefined reference : %s", nombre);
}

void set_lim_mem(int lim) 
{
	LIMITE_MEMORIA_REGISTROS = lim;
}
