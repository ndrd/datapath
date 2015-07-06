#include "alu.h"
#include <stdio.h>

void add(int dest, int reg1, int reg2)
{	
		
	int a = registros[reg1].data;
	int b = registros[reg2].data;
	registros[dest].data=a+b;
	
	return;
}

 
void sub(int dest,int reg1,int reg2)
{	

	int a=registros[reg1].data;
	int b=registros[reg2].data;
	
	registros[dest].data=a-b;
	
	return;
}

void mul (int dest,int reg1,int reg2)
{	
		
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	
	registros[dest].data=a*b;
	
	return;
}	
void divi (int dest,int reg1,int reg2)
{	
		
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	if(b <= 0)
		tirar_error(DIVISION_CERO) ;

	registros[dest].data=a/b;

	return;
}


void fadd(int dest,int reg1,int reg2)
{	
	float a=(float)registros[reg1].data;
	float b=(float)registros[reg2].data;
	registros[dest].data=a+b;
	return;
}

 
void fsub(int dest,int reg1,int reg2)
{	
		
	float a=(float)registros[reg1].data;
	float b=(float)registros[reg2].data;
	
	registros[dest].data=a-b;

	return;
}
void fmul (int dest,int reg1,int reg2)
{	
		
	float a=(float)registros[reg1].data;
	float b=(float)registros[reg2].data;

	registros[dest].data=a*b;
	
	return;
}	
void fdiv (int dest,int reg1,int reg2)
{	
		
	float a=(float)registros[reg1].data;
	float b=(float)registros[reg2].data;
	if(b <= 0)
		tirar_error(DIVISION_CERO) ;
	registros[dest].data = a / (b * 1.0);

	return;
}


void and(int dest,int reg1,int reg2)
{	

	int a=registros[reg1].data;
	int b=registros[reg2].data;
	
	registros[dest].data = a & b;
	
	return;
}
 


void or(int dest,int reg1,int reg2)
{
		
	float a = (float)registros[reg1].data;
	float b = (float)registros[reg2].data;
	int integer = (int) a;
	float residuo = a - integer;
	if (residuo != 0)
		a = a * 10000000; 
	registros[dest].data = ((int)a | (int)b);
	
	return;
}
 
void not(int dest, int reg1)
{
	int a = (int)registros[reg1].data;
	registros[dest].data = ~a;
	return;
}
 
 void xor(int dest,int reg1,int reg2)
{
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	registros[dest].data= a ^ b;

	return;
}
 
 

void li(int dest, int val)
{
	registros[dest].data = val;
}


void lw(int dest,int addr, memoria_ram *ram)
{
	registros[dest].data = ram->rows[addr].data;
	
	
	return;
}

void sw(int dest, int addr, memoria_ram *ram)
{
	ram->rows[addr].data = registros[dest].data;
	
	return;	
}

void lb(int dest,int addr,memoria_ram *ram)
{
	registros[dest].data=(ram->rows[addr].data);
	
	return;
}

void sb(int dest,int addr,memoria_ram *ram)
{
	ram->rows[addr].data=registros[dest].data;
	
	return;	
}

void b(int pc_dest)
{	
	if(pc_dest > 8)
	{
		tirar_error(DIRECCION_INVALIDA);
	}
	return;
}

void beqz(int pc_dest)
{	
	//volcar_memoria();
	if(pc_dest > 8)
	{
		tirar_error(DIRECCION_INVALIDA);
	}
	if (pc_dest == 0)
		return;
	else
		return;

}
void bltz(int pc_dest)
{	
	if(pc_dest > 8)
	{
		tirar_error(DIRECCION_INVALIDA);
	}
	if(pc_dest < 0)
		return;
	else
		return;

}


int syscalli(int total_ciclos)
{
	if(registros[8].data >= 9 || registros[8].data < 0)
	{
		tirar_error(LLAMADA_SYS_INVALIDA);
	}
	
	volcar_memoria();

	if(registros[8].data >= 9 || registros[8].data < 0)
	{
		tirar_error(LLAMADA_SYS_INVALIDA);
	}

	/* Escritura */
	if(registros[8].data==4)
	{ 
		printf("%d\n",(int)registros[9].data);
	}
	if(registros[8].data==5)
	{ 
		printf("%c\n",(char)registros[9].data);
	}
	if(registros[8].data==6)
	{ 
		printf("%f\n",(float)(registros[9].data/10000000));
	}
	if(registros[8].data==7)
	{ 
		int addr = (int)registros[10].data;
		printf("%s","aa");
	}

	if(registros[8].data==8)
	{ 
		printf("\n%d\n", total_ciclos);
		return 0;
		exit(0);
	}

	/* Lectura 
	if(registros[9].data==4)
	{ 
		scanf("%d",&registros[9].data);
		registros[9].data = registros[9].data;
		printf("--%d\n",registros[9].data);
	}
	if(registros[9].data==5)
	{ 
		scanf("%d",&registros[9].data);
		registros[9].data = registros[9].data;
		printf("--%d\n",registros[9].data);
	}
	if(registros[9].data==6)
	{ 
		scanf("%d",&registros[9].data);
		registros[9].data = registros[9].data;
		printf("%d\n",registros[9].data);
	}
	if(registros[9].data==7)
	{ 
		scanf("%d",&registros[9].data);
		registros[9].data = registros[9].data;
		printf("%d\n",registros[9].data);
	}
	*/
	
<<<<<<< Updated upstream

	
=======
		
>>>>>>> Stashed changes
	
	return 1;	
}