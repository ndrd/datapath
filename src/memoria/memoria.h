 #ifndef MEMORIA_REGISTROS
#define MEMORIA_REGISTROS

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int LIMITE_MEMORIA;

unsigned int [] RAM;

void guardar(int i ,struct registros *registros ,char *nmbr_var,int valor);
int get_lugar(char *nmbr_var,struct registros *registros);
void set_lim_mem(int lim);

#endif	