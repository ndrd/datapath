#ifndef ERRORES_H
#define ERRORES_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*
1 División entre cero
2 Dirección de memoria inválida
3 Memoria agotada
4 Número de rigistro inválido
5 Código de operacion inválido
6 Código de llamada a sistema inválido
*/

#define DIVISION_CERO			1
#define DIRECCION_INVALIDA		2
#define MEMORIA_AGOTADA			3
#define REGISTRO_INVALIDO		4
#define OPERACION_INVALIDA		5
#define LLAMADA_SYS_INVALIDA	6	

void tirar_error (int clave_error);
void volcar_memoria();

#endif