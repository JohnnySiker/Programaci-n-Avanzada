    #include <stdio.h>

#define TAMANO 1000

static char buffer[TAMANO];
static char *apBuffer = buffer;

char *almacenar(int caracteres){
	if (buffer+TAMANO-apBuffer >= caracteres){
		apBuffer += caracteres;
		return apBuffer - caracteres;
	}else{
		return 0;
	}
}

void liberar(int caracteres){
	if (apBuffer-buffer >= caracteres){
		apBuffer -= caracteres;
		printf("Se liberaron %d caracteres\n",caracteres);
	}else{
		printf("El numero de caracteres a liberar rebasa el tamaño del buffer\n");
	}
}

void mostrarMenu(){
	printf("\nQue deseas hacer?\n");
	printf("1. Almacenar caracteres(reservar memoria)\n");
	printf("2. Liberar espacio \n");
	printf("3. Imprimir contenido de buffer\n");
	printf("4. Imprimir contenido de real\n");
	printf("5. Salir\n");
}

int main(){
	int opcion = 0;
	int noCaracteres;
	char *lugarEscribir;
	
	while(opcion!=5){
		mostrarMenu();
		scanf("%d",&opcion);

		switch (opcion){
			case 1:
				printf("\nIngresa numero de caracteres: ");
				scanf("%d",&noCaracteres);
				lugarEscribir = almacenar(noCaracteres);
				printf("Ingresa la cadena: ");
				getchar();
				fgets(lugarEscribir,noCaracteres+1,stdin);
			break;
			case 2:
				printf("\nCuantos caracteres quieres liberar?\n");
				scanf("%d",&noCaracteres);
				liberar(noCaracteres);
			break;
			case 3:
				for (int i = 0; i < TAMANO; i++){
					printf("%c", buffer[i]);
				}
			break;
			case 4:
				for (int i = 0; i < apBuffer-buffer; i++){
					printf("%c", buffer[i]);
				}
			break;
		}
	}

	return 0;
}


