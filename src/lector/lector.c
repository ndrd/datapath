#include <string.h>
#include <stdlib.h>
#include "lector.h"
#include "../instrucciones/instrucciones.h"

void showbits(unsigned int x);


int cargar_binario(FILE *archivo, memoria_instrucciones *mar, memoria_ram *ram) 
{
	
	int i = 0;
	char instruccion = '0';

	char *stack;
	int n_stacks = 0;
	int ASCII_SPACE = 32;

	/* leemos los 32 bits */

	while(1 == fread(&instruccion, 1, 1, archivo))
	{

		int r1,r2,r3;

		if (instruccion > ASCII_SPACE) {
			printf("%c", instruccion );
			while(1 == fread(&instruccion, 1, 1, archivo) && instruccion != '\0');
				// printf("%c",instruccion );
			// printf("\n");
			while(1 == fread(&instruccion, 1, 1, archivo) && instruccion == '\0');

		} 
		if (instruccion == LI) {
			int dato;
			fread(&r1, 1, 1, archivo);
			fread(&dato, 4 , 1, archivo);

			r1 = r1  & 0x000000ff;
			dato = (dato >> 24) & 0x000000ff;
			printf("%d -  %d - %d \n", instruccion, r1 , dato );

			tabla_etiquetas.indice[tabla_etiquetas.n].n_instruccion = mar->n;
			tabla_etiquetas.indice[tabla_etiquetas.n++].byte_dir = dato;

			agrega_instruccion(mar, crea_instruccion_i(instruccion, r1 , dato));
		} else {
			fread(&r1, 1, 1, archivo);
			fread(&r2, 1, 1, archivo);
			fread(&r3, 1, 1, archivo);

			r1 = (r1 & 0x000000ff);
			r2 = (r2 & 0x000000ff);
			r3 =  (r3& 0x000000ff);

			printf("%d -  %d - %d - %d\n",instruccion, r1, r2, r3 );
			agrega_instruccion(mar, crea_instruccion_r(instruccion, r1, r2, r3));

		} 
	}

		
	return 0;
	
}  


void showbits(unsigned int x)
{
	int i; 
	for(i=(sizeof(int)*8)-1; i>=0; i--)
		(x&(1<<i))?putchar('1'):putchar('0');
	printf("\n");
}

