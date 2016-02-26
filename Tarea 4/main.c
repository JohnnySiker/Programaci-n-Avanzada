#include <stdio.h>
#include <stdlib.h>

struct tipoDeDatos{
	int i;
	float f;
};


void invertirMatriz(int *A,int *B){
	for (int i = 15; i >= 0; i--){
		*(A++) = *(B+i);
	}
}

void imprimirMatriz(int matriz[4][4]){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			printf("%d \t", matriz[i][j]);
		}
		printf("\n");
	}
}

void multiplicarMatriz(int A[4][4],struct tipoDeDatos C,FILE *f){
	float aux = 0;
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			aux = (float)A[i][j]*(float)C.i*C.f;
			printf("%.2f\t",aux );
			fprintf(f,"%f\t", aux);
		}
		printf("\n");
		fprintf(f,"\n");
	}

	fclose(f);
}



int main(int argc, char  *argv[]){
	int A[4][4];
	int B[4][4];
	int aux = 1;
	struct tipoDeDatos C = {2,3.87};
	

	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			B[i][j] = aux++;

		}
	}
	invertirMatriz(&A[0][0],&B[0][0]);
	
	printf("Matriz invertida: \n");
	imprimirMatriz(A);

	printf("\nMatriz multiplicada: \n");

	multiplicarMatriz(A,C,fopen((argc > 1 ? argv[1]:"resultado.txt"),"w"));
/*
	if (argc > 1){
		multiplicarMatriz(A,C,fopen(argv[1],"w"));
	}else{
		multiplicarMatriz(A,C,fopen("resultado.txt","w"));
	}*/
	
	

	return 0;
}