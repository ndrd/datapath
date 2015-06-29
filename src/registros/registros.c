#include "registros.h"
#include "../errores/errores.h"

registro registros[14];

void iniciar_registros()
{
	strcpy(registros[0].nombre, "r0");
	strcpy(registros[1].nombre, "r1");
	strcpy(registros[2].nombre, "r2");
	strcpy(registros[3].nombre, "r3");
	strcpy(registros[4].nombre, "r4");
	strcpy(registros[5].nombre, "r5");
	strcpy(registros[6].nombre, "r6");
	strcpy(registros[7].nombre, "r7");
	strcpy(registros[8].nombre, "a0");
	strcpy(registros[9].nombre, "a1");
	strcpy(registros[10].nombre, "s0");
	strcpy(registros[11].nombre, "ra");
	strcpy(registros[12].nombre, "pc");
	strcpy(registros[13].nombre, "p");
	return;
}

int n_registro(char* nombre)
{
	int i;
	//Revisa si lo que le pasaron es el numero de registro o su nombre alternativo
	i = strlen(nombre);
	
	if (i == 1)
		return nombre[0]-'0';
	//Si es el nombre,buscamos el nombre en la lista de registros
	// para encontrar el numero
	for (i = 0 ; i < 14 ; i++)
	{		
		if(!strcmp(registros[i].nombre, nombre))
			return i;
	}
	
	return tirar_error(REGISTRO_INVALIDO);
}