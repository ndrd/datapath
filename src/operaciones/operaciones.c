#include "../registros/registros.h"
#include "data_mem.h"
#include "instruction_mem.h"



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

void and_(int dest,int reg1,int reg2)
{	

	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	
	registros[dest].val=a & b;
	pc++;
	return;
}
 


void or_(int dest,int reg1,int reg2)
{
		
			
	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	
	registros[dest].val=a | b;
	pc++;
	
	
	return;
}
 
void slt(int dest,int reg1,int reg2)
{	

	int a=(reg1<32)?registros[reg1].val:reg1-32;
	int b=(reg2<32)?registros[reg2].val:reg2-32;
	
	registros[dest].val=(a<b)?1:0;
	pc++;
	

	return;
}


void li(int dest,int val)
{
	
	registros[dest].val=val;
	pc++;
	
		
	return;
}


void move(int dest,int src)
{
	
	registros[dest].val=reg_file[src].val;
	pc++;
		
	
	return;
}

void load_word(int dest,int addr,struct data_mem*dm)
{

	
	registros[dest].val=(dm->mem[addr].val);
	pc++;
	return;
}

void store_word(int dest,int addr,struct data_mem*dm)
{

	dm->mem[addr].val=registros[dest].val;
	pc++;
	return;	
}
void jump(int pc_dest)
{	
	pc=labels.label[pc_dest].inst_num;

	return;
}

void beq(int reg1,int reg2,int pc_dest)
{
	if(registros[reg1].val==registros[reg2].val)
		pc=labels.label[pc_dest].inst_num;
	else
		pc++;
		
	
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