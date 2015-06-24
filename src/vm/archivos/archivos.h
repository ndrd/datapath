#ifndef ARCHIVOS_INCLUDE
#define ARCHIVOS_INCLUDE

/*
* Leemos un archivo dado, y usando el compilador que se
* incluyo en el proyecto, lo volveremos binario, para despues
* leerlo, y hacer el fetch de las instrucciones.
*/

void compilar_instrucciones(
				FILE *fuente, 
				struct registros *memoria,
				struct memora_instrucciones *instrucciones);
