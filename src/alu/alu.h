#ifndef ALU_H
#define ALU_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../errores/errores.h"
#include "../registros/registros.h"
#include "../errores/errores.h"
#include "../memoria/memoria.h"
#include "../instrucciones/instrucciones.h"


int pc;

void add (int dest,int reg1,int reg2);		
void sub (int dest,int reg1,int reg2);		
void mul (int dest,int reg1,int reg2);	
void divi (int dest,int reg1, int reg2);	
void fadd (int dest,int reg1,int reg2);	
void fsub (int dest,int reg1,int reg2);		
void fmul (int dest,int reg1,int reg2);	
void fdiv (int dest,int reg1,int reg2);		
void and(int dest,int reg1,int reg2);		
void or (int dest,int reg1,int reg2);	
void xor (int dest,int reg1,int reg2);	
void not (int dest, int reg1);		
void lb (int dest,int reg1,memoria_ram *ram);		
void lw (int dest,int addr, memoria_ram *ram);	
void sb (int dest,int reg1, memoria_ram *ram);	
void sw (int dest,int addr, memoria_ram *ram);	
void li(int dest,int val);
void b(int num);		
void beqz (int num);	
void bltz (int num);		
int syscalli(int total_ciclos);								

#endif		

