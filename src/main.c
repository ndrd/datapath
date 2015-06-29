#include "simulador.h"

int memoria_usuario_bytes(int argc, char** argv);
void print_help();

int main (int argc, char **argv)
{
	int lmt_mem = memoria_usuario_bytes(argc, argv);
	/* construimos la memoria ram */
	memoria_ram *ram = init_ram(lmt_mem);
	/* inicializamos los registros */
	iniciar_registros();
	/* memoria de los registros */
	memoria_instrucciones *mar = init_mar();// = init_mar();
	/* leemos el archivo binario de 32 en 32 registros */
	if (argc != 4) {
		print_help();
		return	0;
	}

	FILE *archivo = NULL;
	archivo = fopen(argv[3], "rb");
	
	if (archivo == NULL) {
		printf("archivo invalido\n"); 	
	} else {
		run_simulator(ram, mar, archivo);
	}

	return (0);

}

int 
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

	int mem = -1;
	
	if (str_memoria != NULL)
		sscanf(str_memoria, "%d", &mem);

	return mem;	
}

void print_help() 
{
	printf("Uso : ./myvm -m MEMORIA_TOTAL  codigo_maquina\n");
}