#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "memoria/memoria.h"

long memoria_usuario_bytes(int argc, char** argv);
void print_help();

main (int argc, char **argv)
{

	int lmt_mem = memoria_usuario_bytes(argc, argv);
	memoria_ram ram* = init_ram(lmt_mem);


	
	guardar_ram(5, ram, "aaa", 5646545);
	int i = get_index_ram("aaa", ram);
	printf("%d\n",i);

}

long 
memoria_usuario_bytes(int argc, char** argv)
{
	if (argc < 2) {
		print_help();
		return -1;
	}
	/* usando get_ops como se ve en el manual de GNU */
	char *str_memoria = NULL;
	int index;
	int c;

	opterr = 0;
	while ((c = getopt (argc, argv, "m:")) != -1)
		switch (c)
		{
			case 'm':
			str_memoria = optarg;
			break;
			case '?':
			if (optopt == 'm')
				fprintf (stderr, "La opcion -%c requiere especificar el tamaño de la memoria.\n", optopt);
			else if (isprint (optopt))
				fprintf (stderr, "Opcion invalida `-%c'.\n", optopt);
			else
				fprintf (stderr,
					"Opcion desconocida `\\x%x'.\n",
					optopt);
			return -1;
			default:
				print_help ();
		}

	char *nchr;
	long mem = strtol(str_memoria, &nchr, 10);
	return mem;	
}

void print_help() 
{
	printf("Uso : ./myvm -m MEMORIA_TOTAL  codigo_maquina\n");
}