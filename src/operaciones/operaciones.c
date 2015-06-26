#include "operaciones.h"
#include "../vm/errores.c"


void add(int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	registros[dest].val=a+b;
	pc++;

	return;
}

 
void sub(int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	
	registros[dest].val=a-b;
	pc++;

	return;
}
void mul (int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	
	registros[dest].val=a*b;
	pc++;

	return;
}	
void div (int dest,int reg1,int reg2)
{	
		
	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	if(b <= 0)tirar error(1) ;
	registros[dest].val=a/b;
	pc++;

	return;
}


void fadd(float dest,float reg1,float reg2)
{	
		
	float a=(reg1<32)?registros[reg1].val:reg1-32;
	float b=(reg2<32)?registros[reg2].val:reg2-32;
	registros[dest].val=a+b;
	pc++;

	return;
}

 
void fsub(float dest,float reg1,float reg2)
{	
		
	float a=(reg1<32)?registros[reg1].val:reg1-32;
	float b=(reg2<32)?registros[reg2].val:reg2-32;
	
	registros[dest].val=a-b;
	pc++;

	return;
}
void fmul (float dest,float reg1,float reg2)
{	
		
	float a=(reg1<32)?registros[reg1].val:reg1-32;
	float b=(reg2<32)?registros[reg2].val:reg2-32;

	registros[dest].val=a*b;
	pc++;

	return;
}	
void fdiv (float dest,float reg1,float reg2)
{	
		
	float a=(reg1<32)?registros[reg1].val:reg1-32;
	float b=(reg2<32)?registros[reg2].val:reg2-32;
	if(b <= 0)tirar error(DIVISION_CERO) ;
	registros[dest].val= a / b;
	pc++;

	return;
}


void and(int dest,int reg1,int reg2)
{	

	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	
	registros[dest].val = a & b;
	pc++;
	return;
}
 


void or(int dest,int reg1,int reg2)
{
		
			
	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	
	registros[dest].val = a | b;
	pc++;
	
	
	return;
}
 
void not(int reg1)
{
				
	int a=(reg1<32)?registros[reg1].val:reg1-32;
	
	a = -a
	pc++;
	
	return;
}
 
 void xor(int dest,int reg1,int reg2)
{
		
			
	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	
	registros[dest].val= ((a + b) * ((-a) + (-b))) ;
	pc++;
	
	
	return;
}
 
 

void li(int dest,int val)
{
	
	registros[dest].val=val;
	pc++;
	
		
	return;
}


void lw(int dest,int addr,struct data_mem*dm)
{

	
	registros[dest].val=(dm->mem[addr].val);
	pc++;
	return;
}

void sw(int dest,int addr,struct data_mem*dm)
{

	dm->mem[addr].val=registros[dest].val;
	pc++;
	return;	
}
void b(int pc_dest)
{	
	pc=labels.label[pc_dest].inst_num;

	return;
}
void beqz(int pc_dest)
{	
	if(pc_dest == 0)
	pc=labels.label[pc_dest].inst_num;
else
	return;

}
void bltz(int pc_dest)
{	
	if(pc_dest < 0)
	pc=labels.label[pc_dest].inst_num;
else
	return;

}


void syscall()
{

	if(registros[2].val==1)
	{

		printf("%d\n",reg_file[4].val);		
	}
	else if(registros[2].val==5)
	{
		scanf("%d",&registros[2].val);

	}
	else if(registros[2].val==10)
	{

		exit(0);
	}	
	
	pc++;
	return;	
}