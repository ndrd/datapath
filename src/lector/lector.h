#include <stdio.h>
#include <string.h>
#include <malloc.h>


#include "../instruccion/instruccion.h"
#include "../memomoria/memoria.h"

int read_file(FILE*archivo,struct instruccion_mem*im,struct memoria_ram *ram);   
 
void put_to_file(FILE*archivo,struct instruccion_mem*im,int len,struct memoria_ram *ram);
char* int2bin(int input,int len,char*bin);

#endif 	