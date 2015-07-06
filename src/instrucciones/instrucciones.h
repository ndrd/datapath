#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../memoria/memoria.h"
#include "../registros/registros.h"
#include "../alu/alu.h"

#define LIMITE_MEMORIA_INSTRUCCIONES 1024

int pc;


#define ADD 		0x00	
#define SUB 		0x01
#define MUL 		0x02		
#define DIV 		0x03		
#define FADD 		0x04		
#define FSUB 		0x05		
#define FMUL 		0x06	
#define FDIV 		0x07		
#define ANDR 		0x08		
#define OR 			0x09		
#define XOR 		0x0A
#define NOT 		0x0B
#define LB 			0x0C
#define LW 			0x0D
#define SB 			0x0E
#define SW 			0x0F
#define LI 			0x10	
#define B 			0x11		
#define BEQZ 		0x12
#define BLTZ 		0x13
#define SYSCALL 	0x14

/* duracion en ciclos de reloj de cada instruccion  */
#define C_ADD 			3	
#define C_SUB 			4
#define C_MUL 			10		
#define C_DIV 			11		
#define C_FADD 			4		
#define C_FSUB 			5		
#define C_FMUL 			9	
#define C_FDIV 			10		
#define C_ANDR 			1		
#define C_OR 			1		
#define C_XOR 			1
#define C_NOT 			1
#define C_LB 			500
#define C_LW 			1500
#define C_SB 			700
#define C_SW 			2100
#define C_LI 			1500	
#define C_B 			1		
#define C_BEQZ 			4
#define C_BLTZ 			5
#define C_SYSCALL 		50


typedef enum {
	R, I, J
} tipo_instruccion;

typedef struct 
{
	tipo_instruccion tipo;
	int opcode;
	int r1;
	int r2;
	int r3;
	float dato;
	short tiempo_ciclos;
} instruccion;

typedef struct 
{
	int pc;
	int n;
	char * byte_code;
	instruccion rows[LIMITE_MEMORIA_INSTRUCCIONES];
} memoria_instrucciones;

struct etiqueta {
	char nombre[20];
	int n_instruccion;
	int byte_dir;	
};

int num_label;

struct 
{
	int limite;
	int n;
	struct etiqueta indice[100];

} tabla_etiquetas;


memoria_instrucciones *init_mar();	
instruccion *crea_instruccion_r(int opcode, int r1, int r2, int r3);
instruccion *crea_instruccion_i(int instruccion, int r1,  int dato); 
instruccion *crea_instruccion_j(int instruccion,  int ubicacion);

int get_n_instruccion(memoria_instrucciones *mar, int byte_addr);

void agrega_instruccion(memoria_instrucciones *mar, instruccion *instruccion);
void dump_instruccion(instruccion *ins);

#endif 