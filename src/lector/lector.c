#include <string.h>
#include <stdlib.h>
#include "lector.h"
#include "../instrucciones/instrucciones.h"

void showbits(unsigned int x);


int cargar_binario(FILE *archivo, memoria_instrucciones *im, memoria_ram *ram) 
{
	
	int i = 0;
	char instruccion = '0';

	/* leemos los 32 bits */
	while(1 == fread(&instruccion, 1, 1, archivo))
	{
		int r1,r2,r3;

		if (instruccion == LI) {
			unsigned int dato = 0;
			fread(&r1, 1, 1, archivo);
			fread(&dato, 4 , 1, archivo);
			printf("%d -  %d - %d \n", instruccion, (r1 ) & 0x000000ff, (dato >> 24) & 0x000000FF);
			
		} else {
			fread(&r1, 1, 1, archivo);
			fread(&r2, 1, 1, archivo);
			fread(&r3, 1, 1, archivo);
			printf("%d -  %d - %d - %d\n",instruccion, (r1) & 0x000000ff, r2 & 0x000000ff, r3& 0x000000ff );
		}
	}
		
	return 0;
	
}  

/*
int e = (instruccion ) & 0x000000ff;
int f = (instruccion >> 8) & 0x000000ff;
int g = (instruccion >> 16) & 0x000000FF;
int h = (instruccion >> 24) & 0x000000FF;
printf("%d - %d - %d - %d\n", instruccion , f, g, h);
*/


void showbits(unsigned int x)
{
	int i; 
	for(i=(sizeof(int)*8)-1; i>=0; i--)
		(x&(1<<i))?putchar('1'):putchar('0');
	printf("\n");
}

