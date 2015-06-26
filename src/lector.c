#include <stdio.h>
#include <stdlib.h>

int instructionMemory[50][32];  

void guardarInstruccion(char *linea, int renglon)
{
  int i;
  for(i = 0; i < 32; i++)
    instructionMemory[renglon][i] = linea[i]-'0';
}