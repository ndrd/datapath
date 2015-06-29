#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "memoria/memoria.h"
#include "registros/registros.h"
#include "instrucciones/instrucciones.h"
#include "lector/lector.h"

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
	switch (instr->opcode)	 {
		case ADD :
			*(total_de_ciclos) += C_ADD; 	
			break;
		case SUB :
			*(total_de_ciclos) += C_SUB; 	
			break;
		case MUL :
			*(total_de_ciclos) += C_MUL; 			
			break;
		case DIV :
			*(total_de_ciclos) += C_DIV; 			
			break;
		case FADD :
			*(total_de_ciclos) += C_FADD; 			
			break;
		case FSUB :
			*(total_de_ciclos) += C_FSUB; 			
			break;
		case FMUL :
			*(total_de_ciclos) += C_FMUL; 		
			break;
		case FDIV :
			*(total_de_ciclos) += C_FDIV; 			
			break;
		case ANDR :
			*(total_de_ciclos) += C_ANDR; 			
			break;
		case OR:
			*(total_de_ciclos) += C_OR; 			
			break;
		case XOR :
			*(total_de_ciclos) += C_XOR; 	
			break;
		case NOT :
			*(total_de_ciclos) += C_NOT; 	
			break;
		case LB 	:
			*(total_de_ciclos) += C_LB;  	
			break;
		case LW 	:
			*(total_de_ciclos) += C_LW;  	
			break;
		case SB 	:
			*(total_de_ciclos) += C_SB;  	
			break;
		case SW :
			*(total_de_ciclos) += C_SW;  	
			break;
		case LI :
			*(total_de_ciclos) += C_LI;  		
			break;
		case B :
			*(total_de_ciclos) += C_B;  			
			break;
		case BEQZ :
			*(total_de_ciclos) += C_BEQZ; 	
			break;
		case BLTZ :
			*(total_de_ciclos) += C_BLTZ; 	
			break;
		case SYSCALL:
			*(total_de_ciclos) += C_SYSCALL;  
		break;
	}

}




