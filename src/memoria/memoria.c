
#include "memoria.h"

void guardar(int busca,struct registros *dm,char*var_name,int val)
{
	if(busca >= LIMITE_MEMORIA)
	{
		printf("No hay suficiente espacio");
		exit(2);				// exit code 2 => no hay suficiente espacio.
	}
	
	
	strcpy(dm->mem[pos].var_elemento,var_elemento);
	dm->mem[pos].val=val;
	return;
}

int get_lugar(char*var_name,struct registros *dm)
{
	int i;
	for(i=0;i< LIMITE_MEMORIA;i++)
	{
		if(!strcmp(var_elemento,dm->mem[i].var_elemento))
			return i;
	}
	
	// Si no coincide muestra error
	printf("Undefined reference : %s", var_elemento);
}