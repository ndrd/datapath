
#include "memoria.h"

void store(int pos,struct registros *dm,char*var_name,int val)
{
	if(pos>=1024)
	{
		printf("No hay suficiente espacio");
		exit(2);				// exit code 2 => no hay suficiente espacio.
	}
	
	
	strcpy(dm->mem[pos].var_name,var_name);
	dm->mem[pos].val=val;
	return;
}

int get_mem(char*var_name,struct registros *dm)
{
	int i;
	for(i=0;i<1024;i++)
	{
		if(!strcmp(var_name,dm->mem[i].var_name))
			return i;
	}
	
	// Si no coincide muestra error
	printf("Undefined reference : %s", var_name);
}