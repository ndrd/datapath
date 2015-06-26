#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "../registros/registros.h"
#include "../memoria/memoria.h"
#include "../instrucciones/instrucciones.h"

int pc;

void add (int dest,int reg1,int reg2);		
void sub (int dest,int reg1,int reg2);		
void mul (int dest,int reg1,int reg2);	
void div (int dest,int reg1,int reg2);	
void fadd (float dest,float reg1,float reg2);	
void fsub (float dest,float reg1,float reg2);		
void fmul (float dest,float reg1,float reg2);	
void fdiv (float dest,float reg1,float reg2);		
void and(int dest,int reg1,int reg2);		
void or (int dest,int reg1,int reg2);	
void xor (int dest,int reg1,int reg2);	
void not (int num);		
void lb (int dest,int reg1,int reg2);		
void lw (int dest,int addr,struct data_mem*dm);	
void sb (int dest,int reg1,int reg2);	
void sw (int dest,int addr,struct data_mem*dm);	
void li(int dest,int val);
void b(int num);		
void beqz (int num);	
void bltz (int num;		
void syscall();								


 #endif		

