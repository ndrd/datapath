#ifndef MEMORIA_PRINCIPAL
#define MEMORIA_PRINCIPAL

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int LIMITE_MEMORIA;

typedef enum {
	BYTE,
	WORD,
	INT,
	FLOAT,	
} type;

/* representa la memoria de datos puede almacenar */
struct memoria_datos
{
	struct celda
	{	
		type tipo_dato;
		/* el nombre de la variable almacenada */
		char nombre[16];
		/* int de 32 bits, justo lo que necesitamos */
		int data;
	} celdas[1024];
};

/* almacena el dato dentro de la memoria, de la mano del nombre de la variable que se le asigno */
void guardar(int index, struct memoria_datos *memoria, char *nombre, int data);
/* nos da su posicion dentor del arreglo de la memoria */
int get_index(char *nombre, struct memoria_datos *memoria);
/* establece el limite de la memoria */
void set_lim_mem(int lim);

#endif	