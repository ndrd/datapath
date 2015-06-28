#ifndef LECTOR_INCLUDED
#define LECTOR_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../instrucciones/instrucciones.h"
#include "../memoria/memoria.h"

int read_file(FILE*archivo, memoria_instrucciones *im, memoria_ram *ram);   
 

#endif 	