#include <stdio.h>
#include <string.h>
#include "Student.c"


#define TAM 100
struct Student alumnos[TAM];
int studentsCount = 0;
#include "Middleware.c"




int main(){

	int opcion = 0;
	struct Student Student;
	readDB(fopen("alumnos.db","r"));

	while(opcion!=3){
		showMenu();
		scanf("%d",&opcion);

		switch(opcion){
			case 1:
				printf("No. Lista: ");
				scanf("%s",Student.id);
				printf("Nombre: ");
				scanf("%s",Student.name);
				printf("Promedio: ");
				scanf("%s",Student.average);
				addStudent(fopen("alumnos.db","a+"),Student);
			break;
			case 2:
				for (int i = 0; i < studentsCount; ++i){
					printf("%s.- %s %s\n",alumnos[i].id,alumnos[i].name, alumnos[i].average);
				}
			break;
		}
	}
	
	return 0;
}
