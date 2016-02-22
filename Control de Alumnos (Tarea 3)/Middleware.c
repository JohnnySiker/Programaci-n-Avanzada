struct Student maxAverage(){
	struct Student bestStudent = alumnos[0];
	
	for (int i = 1; i<studentsCount;i++){

		float actualMax = atof(bestStudent.average);
		float newMax = atof(alumnos[i].average);	
		if(actualMax<newMax){
		
			bestStudent = alumnos[i];
		}			
	}
	return bestStudent;
}


void currentStudents(char data[]){

	int i = 0,countColon = 0,countSemicolon = 0;
	
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

		memset(&current.id[0],0,sizeof(current.id));
		memset(&current.name[0],0,sizeof(current.name));
		memset(&current.average[0],0,sizeof(current.average));

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
		alumnos[j] = current;
	}
	studentsCount = countSemicolon;
	memset(&data[0],0,sizeof(data));
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




int addStudent(FILE *db,struct Student studentToAdd){
	if (db!=NULL){
		char registro [30];
		sprintf(registro,"%s:%s:%s;",studentToAdd.id,studentToAdd.name,studentToAdd.average);
		printf("%s\n",registro);
		fputs(registro,db);
	
		fclose(db);
		return 0;
	}else{
		return 1;
	}
}

void showMenu(){
	printf("\nAdministrador de Calificaciones\n");
	printf("\n1)Agregar Alumno\n2)Mostrar Alumnos\n3)Mejor alumno\n4)Salir\n");

}
