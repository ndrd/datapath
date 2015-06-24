#ifndef MEMORIA_REGISTROS
#define MEMORIA_REGISTROS

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int LIMITE_MEMORIA_REGISTROS;

struct registros
{
	struct registros_elemento
	{
		char nombre[20];
		int valor;
	}                                                                                                                                                                                                                                                                                                                                          mem[1024]; 
};

void guardar(int i ,struct registros *registros ,char *nmbr_var,int valor);
int get_lugar(char *nmbr_var,struct registros *registros);
void set_lim_mem(int lim);

#endif	