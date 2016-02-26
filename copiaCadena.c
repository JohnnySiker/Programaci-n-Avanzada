#include<stdio.h>

void copiarCadena(char *origen,char *destino){
	
	while(*origen != '\0'){
		*destino++ = *origen++;
	}
	
}
