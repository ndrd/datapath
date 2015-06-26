#include "lector.h"
#include <string.h>

int primer_char(char*linea)
{
	
	int i;
 	for(i=0;(linea[i] == 32 || linea[i] == 9) && linea[i]!='\x0';i++);	
	
	if(linea[i] == 10)
		return -1;
	else
	 	return i;
}

int read_file(FILE*archivo,struct instruccion_mem*im,struct memoria_ram *ram)
{	

	char linea[100],temp[100];
	int i,k,j,linea_num,valor,posicion;
	linea_num = i = k = j = posicion = 0;
	
	int data_text=0;	

	while(!feof(file))
	{	
		linea_num++;
		
		fgets(linea,99,file);
		i = primer_char(linea);
		
		if(i == -1 || linea[i] =='#')
			continue;
			
		if(linea[i] == '.')
		{
			i++;
			for(j = 0;linea[i] != 32 && linea[i] != '\x0' && linea[i] != 10 && linea[i] != 9 && linea[i] != '\n';i++,j++)
			{
				temp[j] = linea[i];
				
			}
			
			temp[j]='\x0';
			
			if(!strcmp("datos",temp))
				data_text = 1;
			else if(!strcmp("texto",temp))
				data_text = 0;
			else
			{
				fprintf(stderr,"Error de sintaxis %d",linea_num);
				exit(1);
			}
			
			continue;
		}
		
		if(data_text == 0)
		{
		
			for(j = 0;linea[i] != '#' && linea[i] != '\x0' && linea[i] != '\n'; i++,j++)
				temp[j] = linea[i];	  
			temp[j] = '\x0';
			
						
			int coded[5];	
			
			encode(temp,coded,ram,k);
			if(coded[0])
			{	
				load_instruccion_mem(im,k,coded);
				k++;
				
			}
				
		}
		
		else if(data_text==1)
		{
			valor=0;
			for(j=0;linea[i]!='#' && linea[i]!='\x0' && linea[i]!='\n' && linea[i]!=32 && linea[i]!=':'; i++,j++)
				temp[j]=linea[i];	     		
				temp[j] = '\x0';

			for(;linea[i] == 32 || linea[i] == ':'; i++,j++);			
			for(;!(linea[i] >= '0' && linea[i] <= '9') && linea[i] != '\x0';i++);	
			
			if(linea[i] != '\x0')
			{	
				for(;linea[i] >= '0' && linea[i] <= '9';i++)
					valor = valor*10+(line[i]-'0');
						
			}
			
			store(posicion,ram,temp,valor);
	
			posicion++;
				
		}	
		
	}
	return k;
}