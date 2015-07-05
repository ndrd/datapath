#include "instrucciones.h"

memoria_instrucciones
*init_mar()
{
	memoria_instrucciones *mar = calloc(LIMITE_MEMORIA_INSTRUCCIONES, sizeof(memoria_instrucciones));
	mar->n = 0;
	return mar;
}

instruccion 
*crea_instruccion_r (int op, int r1, int r2, int r3)
{
	instruccion *instr =  calloc(1, sizeof(instruccion));
	instr->tipo = R;
	instr->r1 = r1;
	instr->r2 = r2;
	instr->r3 = r3;
	instr->dato = -1;
	instr->opcode = op;
	return instr;
}

instruccion 
*crea_instruccion_i(int op, int r1, int dato)
{
	instruccion *instr =  calloc(1, sizeof(instruccion));
	instr->tipo = I;
	instr->r1 = r1;
	instr->dato = dato;
	instr->opcode = op;
	return instr;
}

instruccion 
*crea_instruccion_j(int op, int label)
{
	instruccion *instr;//=  calloc(sizeof(instruccion),1);
	instr->tipo = J;
	instr->r2 = label;
	instr->opcode = op;
	return instr;
}



void dump_instruccion(instruccion *inst)
{
	if (inst == NULL) {
		printf("La instruccion es nula\n"); 
		return;
	}
	/**
	printf("OP: %2d\n", inst->opcode );
	printf("TP: %c\n", (inst->tipo == R) ? 'R' : (inst->tipo == J) ? 'J' : 'I');
	printf("R1: %2d\n", inst->r1 );
	printf("R2: %2d\n", inst->r2 );
	printf("R3: %2d\n", inst->r3 );
	printf("DT: %2f\n", inst->dato );
	printf("\n");*/
}


void 
agrega_instruccion(memoria_instrucciones *mar, instruccion *ins)
{
	mar->rows[mar->n].opcode = ins->opcode;
	mar->rows[mar->n].tipo = ins->tipo;
	mar->rows[mar->n].r1 = ins->r1;
	mar->rows[mar->n].r2 = ins->r2;
	mar->rows[mar->n].r3 = ins->r3;
	mar->rows[mar->n].dato = ins->dato;
	mar->n++;
}
