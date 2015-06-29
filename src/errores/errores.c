#include "../errores/errores.h"
#include "../memoria/memoria.h"
#include "../registros/registros.h"

int
tirar_error (int clave_error)
{
	printf("Se chispo la mierda %d\n",clave_error );
	exit(clave_error);
	return	clave_error;
}

