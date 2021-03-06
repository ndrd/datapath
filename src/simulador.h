#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "memoria/memoria.h"
#include "registros/registros.h"
#include "instrucciones/instrucciones.h"
#include "lector/lector.h"
#include "alu/alu.h"

int ejecuta_instruccion(int *pc, memoria_instrucciones *mar, memoria_ram *ram, int *total_de_ciclos);


void 
run_simulator(memoria_ram *ram, memoria_instrucciones *mar, FILE *binario) 
{
	if (binario != NULL)
		cargar_binario(binario, mar, ram);
	else
		return;

	/* verificamos que las instrucciones se hayan cargado correctamente */
	if (mar->n <= 2)
		printf("Ejecucion terminada correctamente\n");

	int pc = 0;
	int total_de_ciclos = 0;
	int stack_size = 400;

	while(1)
	{
		int exito = ejecuta_instruccion(&pc, mar, ram, &total_de_ciclos);
		if (exito == 0 || --stack_size == 0)
			break;
	}
}


int  ejecuta_instruccion(int *pc, memoria_instrucciones *mar, memoria_ram *ram, int *total_de_ciclos)
{

	if (*(pc) > mar->n)
		return 0;
	instruccion *instr =  &mar->rows[*(pc)];
	int dest =  instr->r1;
	int reg1 = instr->r2;
	int reg2 = instr->r3;
	int num = instr->dato;
	int val = num;

	int tmp;
	
	switch (instr->opcode)	 {
		case ADD:
			add(dest, reg1, reg2);
			*(total_de_ciclos) += C_ADD;
			*(pc) += 1;
			
			break;
		case SUB :
			sub(dest, reg1, reg2);
			*(total_de_ciclos) += C_SUB;
			*(pc) += 1;
			
			break;
		case MUL:
			mul(dest, reg1, reg2);
			*(total_de_ciclos) += C_MUL;
			*(pc) += 1;
			
			break;
		case DIV :
			divi(dest, reg1, reg2);
			*(total_de_ciclos) += C_DIV;
			*(pc) += 1;
			
			break;
		case FADD :
			fadd(dest, reg1, reg2);
			*(total_de_ciclos) += C_FADD;
			*(pc) += 1;
			
			break;
		case FSUB :
			fsub(dest, reg1, reg2);	
			*(total_de_ciclos) += C_FSUB;
			*(pc) += 1;
			
			break;
		case FMUL :
			fmul(dest, reg1, reg2);
			*(total_de_ciclos) += C_FMUL;
			*(pc) += 1;
			
			break;
		case FDIV :
			fdiv(dest, reg1, reg2);
			*(total_de_ciclos) += C_FDIV;
			*(pc) += 1;
			
			break;
		case ANDR:
			and(dest, reg1, reg2);
			*(total_de_ciclos) += C_ANDR;
			*(pc) += 1;
			
			break;
		case OR:
			or(dest, reg1, reg2);
			*(total_de_ciclos) += C_OR;
			*(pc) += 1;
			
			break;
		case XOR :
			xor(dest, reg1, reg2);
			*(total_de_ciclos) += C_XOR;
			*(pc) += 1;

			break;
		case NOT :
			not(instr->r1, instr->r3);
			*(total_de_ciclos) += C_NOT;
			*(pc) += 1;
			
			break;
		case LB:
			lb(dest,reg1,ram);
			*(total_de_ciclos) += C_LB;
			*(pc) += 1;
			
			break;
		case LW:
			lw(dest,reg1,ram);	
			*(total_de_ciclos) += C_LW;
			*(pc) += 1;
		
			break;
		case SB:
			sb(dest,reg1,ram);
			*(total_de_ciclos) += C_SB;
			*(pc) += 1;
		
			break;
		case SW :
			sw(dest,reg1,ram);
			*(total_de_ciclos) += C_SW;
			*(pc) += 1;

			break;
		case LI:

			li(dest,val);
			*(total_de_ciclos) += C_LI;
			*(pc) += 1;
			
			break;
		case B:
			tmp = get_n_instruccion(mar, registros[instr->r3].data);
			*(total_de_ciclos) += C_B;
			*(pc) = (tmp < 2) ? *(pc) + 1 : tmp+1;
			break;
		case BEQZ :
			*(total_de_ciclos) += C_BEQZ;
			tmp = get_n_instruccion(mar, registros[instr->r1].data);

			if (registros[instr->r3].data == 0)
				*(pc) = tmp+1;
			else
				*(pc) += 1;
			break;
		case BLTZ :
			*(total_de_ciclos) += C_BLTZ;
			int dato = (int) registros[instr->r3].data;
			tmp = get_n_instruccion(mar, registros[instr->r1].data);
			if (dato < 0)
				*(pc) = tmp+1;
			else
				*(pc) += 1;
			break;

		case SYSCALL:
			*(total_de_ciclos) += C_SYSCALL;
			*(pc) += 1;
			return syscalli(*total_de_ciclos);


		break;
		default:
			*pc +=1;
			break;
	}
	
	return 1;
}




