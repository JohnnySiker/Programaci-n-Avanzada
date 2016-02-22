#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.c"


#define TAM 100
struct Student alumnos[TAM];
int studentsCount = 0;
#include "Middleware.c"




int main(){

	int opcion = 0;
	struct Student studentToAdd;
	struct Student bestStudent;
	readDB(fopen("alumnos.db","r"));

	while(opcion!=4){
		showMenu();
		scanf("%d",&opcion);

		switch(opcion){
			case 1:
				printf("No. Lista: ");
				scanf("%s",studentToAdd.id);
				printf("Nombre: ");
				scanf("%s",studentToAdd.name);
				printf("Promedio: ");
				scanf("%s",studentToAdd.average);
				addStudent(fopen("alumnos.db","a+"),studentToAdd);
			break;
			case 2:
				readDB(fopen("alumnos.db","r"));
				for (int i = 0; i < studentsCount-1; ++i){
					printf("%s.- %s %s\n",alumnos[i].id,alumnos[i].name, alumnos[i].average);
				}

			break;
			case 3:
				bestStudent = maxAverage();
				printf("El mejor alumno es %s, con promedio de %s",bestStudent.name,bestStudent.average);
			break;
		}
	}
	
	return 0;
}
