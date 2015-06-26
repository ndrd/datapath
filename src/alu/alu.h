#ifndef ALU_H
#define ALU_H

#include "../registros/registros.h"
#include "../memoria/memoria.h"
#include "../instrucciones/instrucciones.h"

int pc;

void add (int dest,int reg1,int reg2);		
void sub (int dest,int reg1,int reg2);		
void mul (int dest,int reg1,int reg2);	
void divi (int dest,int reg1, int reg2);	
void fadd (float dest,float reg1,float reg2);	
void fsub (float dest,float reg1,float reg2);		
void fmul (float dest,float reg1,float reg2);	
void fdiv (float dest,float reg1,float reg2);		
void and(int dest,int reg1,int reg2);		
void or (int dest,int reg1,int reg2);	
void xor (int dest,int reg1,int reg2);	
void not (int num);		
void lb (int dest,int reg1,int reg2);		
void lw (int dest,int addr, memoria_ram *ram);	
void sb (int dest,int reg1,int reg2);	
void sw (int dest,int addr, memoria_ram *ram);	
void li(int dest,int val);
void b(int num);		
void beqz (int num);	
void bltz (int num);		
void syscall();								

#endif		

