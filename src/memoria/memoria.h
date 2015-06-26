#ifndef MEMORIA_PRINCIPAL
#define MEMORIA_PRINCIPAL

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* cada celda almacena 4 bytes */
#define  LIMITE_MEMORIA_DEFAULT = 1024;

typedef enum {
	BYTE,
	WORD,
	INT,
	FLOAT,	
} type;

typedef struct 
{	
	type tipo_dato;
	/* el nombre de la variable almacenada */
	char nombre[16];
	/* int de 32 bits, justo lo que necesitamos */
	int data;
} row;

/* representa la memoria de datos puede almacenar */
typedef struct 
{
	int limite;
	int elementos;
	row *rows;
} memoria_ram;

/* almacena el dato dentro de la memoria, de la mano del nombre de la variable que se le asigno */
void guardar_ram(int index, memoria_ram *memoria, char *nombre, int data);
/* nos da su posicion dentor del arreglo de la memoria */
int get_index_ram(char *nombre, memoria_ram *memoria);
/* establece el limite de la memoria */
memoria_ram init_ram(int lim);

#endif	