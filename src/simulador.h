#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "memoria/memoria.h"
#include "registros/registros.h"
#include "instrucciones/instrucciones.h"
#include "lector/lector.h"
#include "alu/alu.h"

void ejecuta_instruccion(int pc, instruccion *instr, memoria_ram *ram, int *total_de_ciclos);


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

	for (int i = 0; i < mar->n; i++)
		dump_instruccion(&mar->rows[i]);

	int pc = 0;
	int total_de_ciclos = 0;

	while(pc <= mar->n)
	{
		ejecuta_instruccion(pc, &mar->rows[pc], ram, &total_de_ciclos);
		pc++;
	}
	printf("Total de cilcos %d\n", total_de_ciclos);
}

void ejecuta_instruccion(int pc, instruccion *instr, memoria_ram *ram, int *total_de_ciclos)
{
	printf("%d\n", instr->opcode );
	int dest,reg1,reg2,num,val;
	switch (instr->opcode)	 {
		case ADD:
			add(dest, reg1, reg2);
			*(total_de_ciclos) += C_ADD; 	
			break;
		case SUB :
			sub(dest, reg1, reg2);
			*(total_de_ciclos) += C_SUB; 	
			break;
		case MUL:
			mul(dest, reg1, reg2);
			*(total_de_ciclos) += C_MUL; 			
			break;
		case DIV :
			divi(dest, reg1, reg2);
			*(total_de_ciclos) += C_DIV; 			
			break;
		case FADD :
			fadd(dest, reg1, reg2);
			*(total_de_ciclos) += C_FADD; 			
			break;
		case FSUB :
			fsub(dest, reg1, reg2);	
			*(total_de_ciclos) += C_FSUB; 			
			break;
		case FMUL :
			fmul(dest, reg1, reg2);
			*(total_de_ciclos) += C_FMUL; 		
			break;
		case FDIV :
			fdiv(dest, reg1, reg2);
			*(total_de_ciclos) += C_FDIV; 			
			break;
		case ANDR:
			and(dest, reg1, reg2);
			*(total_de_ciclos) += C_ANDR; 			
			break;
		case OR:
			or(dest, reg1, reg2);
			*(total_de_ciclos) += C_OR; 			
			break;
		case XOR :
			xor(dest, reg1, reg2);
			*(total_de_ciclos) += C_XOR; 	
			break;
		case NOT :
			not(num);
			*(total_de_ciclos) += C_NOT; 	
			break;
		case LB:
			lb(dest,reg1,ram);
			*(total_de_ciclos) += C_LB;  	
			break;
		case LW:
			lw(dest,reg1,ram);	
			*(total_de_ciclos) += C_LW;  	
			break;
		case SB:
			sb(dest,reg1,ram);
			*(total_de_ciclos) += C_SB;  	
			break;
		case SW :
			sw(dest,reg1,ram);
			*(total_de_ciclos) += C_SW;  	
			break;
		case LI:
			li(dest,val);
			*(total_de_ciclos) += C_LI;  		
			break;
		case B:
			b(num);
			*(total_de_ciclos) += C_B;  			
			break;
		case BEQZ :
			beqz(num);
			*(total_de_ciclos) += C_BEQZ; 	
			break;
		case BLTZ :
			bltz(num);
			*(total_de_ciclos) += C_BLTZ; 	
			break;
		case SYSCALL:
			syscalli();
			*(total_de_ciclos) += C_SYSCALL;  
		break;
	}

}




