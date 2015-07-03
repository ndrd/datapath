#include "../errores/errores.h"
#include "../memoria/memoria.h"
#include "../registros/registros.h"

int
tirar_error (int clave_error)
{
	char *nombre;

	switch(clave_error) {
	 	case DIVISION_CERO:
	 		nombre = "DIVISION_CERO";
	 		break;
	 	case DIRECCION_INVALIDA:
	 		nombre = "DIRECCION_INVALIDA";
	 		break;
	 	case MEMORIA_AGOTADA:
	 		nombre = "MEMORIA_AGOTADA";
	 		break;
	 	case REGISTRO_INVALIDO:
	 		nombre = "REGISTRO_INVALIDO";
	 		break;
	 	case OPERACION_INVALIDA:
	 		nombre = "OPERACION_INVALIDA";
	 		break;
	 	case LLAMADA_SYS_INVALIDA:
	 		nombre = "LLAMADA_SYS_INVALIDA";
	 		break;
	 }

	printf("%s %d\n",nombre, 	clave_error );
	exit(clave_error);
	return	clave_error;
}

void volcar_memoria() {
	for (int i = 0; i < 14; i++) {
		printf("Registro %s %d valor: %d\n", registros[i].nombre, i, registros[i].data);
	}
}
