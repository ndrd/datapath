#include "alu.h"
#include <stdio.h>

void add(int dest, int reg1, int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;
	registros[dest].data=a+b;
	pc++;

	return;
}

 
void sub(int dest,int reg1,int reg2)
{	

	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;
	
	registros[dest].data=a-b;
	pc++;

	return;
}

void mul (int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;
	
	registros[dest].data=a*b;
	pc++;

	return;
}	
void divi (int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;

	if(b <= 0)
		tirar_error(DIVISION_CERO) ;

	registros[dest].data=a/b;
	pc++;

	return;
}


void fadd(int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;
	registros[dest].data=a+b;
	pc++;

	return;
}

 
void fsub(int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;
	
	registros[dest].data=a-b;
	pc++;

	return;
}
void fmul (int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;

	registros[dest].data=a*b;
	pc++;

	return;
}	
void fdiv (int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;
	if(b <= 0)
		tirar_error(DIVISION_CERO) ;
	registros[dest].data= a / b;
	pc++;

	return;
}


void and(int dest,int reg1,int reg2)
{	

	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;
	
	registros[dest].data = a & b;
	pc++;
	return;
}
 


void or(int dest,int reg1,int reg2)
{
		
			
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;
	
	registros[dest].data = a | b;
	pc++;
	
	
	return;
}
 
void not(int reg1)
{
				
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	
	a = -a;
	pc++;
	
	return;
}
 
 void xor(int dest,int reg1,int reg2)
{
		
	int a=(reg1<32)?registros[reg1].data:reg1-32;
	int b=(reg2<32)?registros[reg2].data:reg2-32;
	
	registros[dest].data= ((a + b) * ((-a) + (-b))) ;
	pc++;
	
	
	return;
}
 
 

void li(int dest, int val)
{
	
	registros[dest].data = val;
	pc++;
	
		
	return;
}


void lw(int dest,int addr, memoria_ram *ram)
{
	registros[dest].data=(ram->rows[addr].data);
	pc++;
	return;
}

void sw(int dest, int addr, memoria_ram *ram)
{
	ram->rows[addr].data = registros[dest].data;
	pc++;
	return;	
}

void lb(int dest,int addr,memoria_ram *ram)
{
	registros[dest].data=(ram->rows[addr].data);
	pc++;
	return;
}

void sb(int dest,int addr,memoria_ram *ram)
{
	ram->rows[addr].data=registros[dest].data;
	pc++;
	return;	
}

void b(int pc_dest)
{	
	pc = tabla_etiquetas.indice[pc_dest].n_instruccion;
	return;
}

void beqz(int pc_dest)
{	
	if (pc_dest == 0)
		pc = tabla_etiquetas.indice[pc_dest].n_instruccion;
	else
		return;

}
void bltz(int pc_dest)
{	
	if(pc_dest < 0)
		pc=tabla_etiquetas.indice[pc_dest].n_instruccion;
	else
		return;

}


void syscall()
{
	if(registros[2].data==1)
	{
		printf("%d\n",registros[4].data);		
	}
	else if(registros[2].data==5)
	{
		scanf("%d",&registros[2].data);

	}
	else if(registros[2].data==10)
	{

		exit(0);
	}	
	
	pc++;
	return;	
}