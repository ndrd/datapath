#ifndef DATA_MEMORY_H_INCLUDED
#define DATA_MEMORY_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int LIMITE_MEMORIA = 50

struct registros
{
	struct registros_elemento
	{
		char var_elemento[20];
		int val;
	
	}                                                                                                                                                                                                                                                                                                                                          mem[1024]; 
};


void guardar(int pos,struct registros *dm,char*var_elemento,int val);
int get_lugar(char*var_elemento,struct registros *dm);			// Regresa el lugar donde se guarda
		

#endif	