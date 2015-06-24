#ifndef REGISTROS_H_INCLUDED
#define REGISTROS_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct registro
{
	char nombre[4];			
	int valor;
};

extern struct registro reg_file[14];


void iniciar_registro();	 
int reg_num(char*nombre);	//Regresa el numero del registro cuando le dan el nombre

#endif 	