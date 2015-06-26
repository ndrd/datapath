#ifndef LECTOR_INCLUDED
#define LECTOR_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../instrucciones/instrucciones.h"
#include "../memoria/memoria.h"

int read_file(FILE*archivo,struct instruccion_mem*im,memoria_ram *ram);   
 
void put_to_file(FILE*archivo,struct instruccion_mem*im,int len, memoria_ram *ram);
char* int2bin(int input,int len,char*bin);

#endif 	