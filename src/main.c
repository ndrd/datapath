#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

 /* usando get_ops como se ve en el manual de GNU */
long 
memoria_usuario(int argc, char** argv);

void
print_help(char** argv);

int
main (int argc, char **argv)
{
	int lmt_mem = memoria_usuario(argc, argv);
}

long 
memoria_usuario(int argc, char** argv)
{
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
		print_help (argv);
	}

	char *nchr;
	long mem = strtol(str_memoria, &nchr, 10);

	return mem;	
}

void 
print_help(char** argv) {
	printf("Uso : %s -m MEMORIA_TOTAL  codigo_maquina\n", argv[0]);
}