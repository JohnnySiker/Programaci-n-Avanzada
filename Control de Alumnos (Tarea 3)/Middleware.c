void currentStudents(char data[]){
	int i = 0,countColon = 0,countSemicolon = 0;
	struct Student students[TAM];
	int colon[TAM*3];
	int semicolon[TAM*3];

	while(data[i] != '\0'){
		if (data[i] == ':'){
			colon[countColon] = i;
			countColon++;
		}else if (data[i] == ';'){
			semicolon[countSemicolon] = i;
			countSemicolon++;
		}
		i++;
	}

	for (int j = 0; j < countSemicolon; j++){
		
		int k = (j == 0? 0:semicolon[j-1]+1);
		struct Student current; 
		int opt = 0;
		int l = 0;

		while(k < semicolon[j]){

			if (data[k] == ':'){
				opt++;
				l = 0;
			}else{
				switch(opt){
					case 0:
						current.id[l] = data[k];
						l++;
					break;
					case 1:
						current.name[l] = data[k];
						l++;
					break;
					case 2:
						current.average[l] = data[k];
						l++;
					break;
				}
			}
			k++;
		}
		opt = 0;
		printf("%s:%s:%s;",current.id,current.name,current.average);
		alumnos[j] = current;
	}
	studentsCount = countSemicolon;
}

void readDB(FILE *db){

	char buffer[2];
	char data[2048];

	while(feof(db) == 0){
		fgets(buffer,2,db);
		strcat(data,buffer);
	}

	currentStudents(data);
	fclose(db);
}




int addStudent(FILE *db,struct Student Student){
	if (db!=NULL){
		char registro [30];
		sprintf(registro,"%s:%s:%s;",Student.id,Student.name,Student.average);
		fputs(registro,db);
		fclose(db);
		studentsCount++;
		alumnos[studentsCount] = Student;
		return 0;
	}else{
		return 1;
	}
}

void showMenu(){
	printf("\nAdministrador de Calificaciones\n");
	printf("\n1)Agregar Alumno\n2)Mostrar Alumnos\n3)Salir\n");

}