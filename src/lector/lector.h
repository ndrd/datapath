#ifndef LECTOR_INCLUDED
#define LECTOR_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../instrucciones/instrucciones.h"
#include "../memoria/memoria.h"

int cargar_binario(FILE *archivo, memoria_instrucciones *mar, memoria_ram *ram);   
 

#endif 	