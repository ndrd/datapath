#ifndef REGISTROS_H_INCLUDED
#define REGISTROS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
	char nombre[4];			
	int data;
} registro;

extern registro registros[14];


void iniciar_registros(void);	 
int n_registro(char *nombre);	//Regresa el numero del registro cuando le dan el nombre

#endif 	