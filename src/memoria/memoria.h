#ifndef DATA_MEMORY_H_INCLUDED
#define DATA_MEMORY_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct registros
{
	struct registros_element
	{
		char var_name[20];
		int val;
	
	}                                                                                                                                                                                                                                                                                                                                          mem[1024]; 
};


void store(int pos,struct registros *dm,char*var_name,int val);
int get_mem_location(char*var_name,struct registros *dm);			// Returns the index where var_name is stored
		

#endif	