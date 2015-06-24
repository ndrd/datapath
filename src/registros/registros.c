#include "registros.h"

struct registro tipo_registro[14];

void iniciar_registro()
{
	

	strcpy(reg_file[0].nombre,"r0");
	strcpy(reg_file[1].nombre,"r1");
	strcpy(reg_file[2].nombre,"r2");
	strcpy(reg_file[3].nombre,"r3");
	strcpy(reg_file[4].nombre,"r4");
	strcpy(reg_file[5].nombre,"r5");
	strcpy(reg_file[6].nombre,"r6");
	strcpy(reg_file[7].nombre,"r7");
	strcpy(reg_file[8].nombre,"a0");
	strcpy(reg_file[9].nombre,"a1");
	strcpy(reg_file[10].nombre,"s0");
	strcpy(reg_file[11].nombre,"ra");
	strcpy(reg_file[12].nombre,"pc");
	strcpy(reg_file[13].nombre,"p");
	
	return;
}

int reg_num(char*nombre)
{
	int i;
	//Revisa si lo que le pasaron es el numero de registro o su nombre alternativo
	i = strlen(nombre);
	
	if (i == 1)
		return nombre[0]-'0';
	//Si es el nombre,buscamos el nombre en la lista de registros
	// para encontrar el numero
	for(i=0 ;i< 14 ; i++)
	{		
		if(!strcmp(reg_file[i].nombre,nombre))
			break;
	}
	
	if(i! = 14)
		return i;
	
	// If i==32, then the name of the register used is either secondary alternate name of some registers or syntax error
	/**if (!strcmp(nombre,"s8")) NO ENTENDI ESTA LINEA
		return 30;   */
	else 
	{
		printf("Syntax error. %s : no existe ese registro",nombre);
		exit(1);				
	} 
}