#include "interpreter.h"

int **instrus;

int count_tmp;

int sizeInstrus;

int sizeInicio = 0;

int **getInstrus() {
	return instrus;
}

int getSizeInstrus() {
	return sizeInstrus;
}

void assignedSpace(int total_instructions) {
	instrus = (int **)malloc(sizeof(int*)*total_instructions);
	for (int i = 0; i < total_instructions; ++i)
	{
		instrus[i] = (int*)malloc(sizeof(int)*LARGO_LINEA);
	}
}

char** strSplit(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* contando los elementos que hay en el string */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* agregando un spacio por cada token*/
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Agregue espacio para terminar la cadena nula de modo que
    el llamador sepa dónde termina la lista de cadenas devueltas. */
    count++;

    count_tmp = count;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int getInstruction(char line[LARGO_LINEA], int itera){
	//printf("cambio de linea%s\n");       line == "bridge1 ="
	char** tokens;
	int *instru_actual;

	int sal = 0;

	printf("Itera: %d\n", itera);
	if (itera == 0) {
		if (strncmp(line, "size", 4) == 0) {
			tokens = strSplit(line, ' ');
			int s = atoi(*(tokens + 1));
			if (s > 0 && s < 4) {
				instrus[itera][0] = 0;
	    		instrus[itera][1] = s;
			} else {
				printf("En size: Rango %d fuera de limites 1-3\n", s);
				sal = -1;
			}
		} else {
			instrus[itera][0] = 0;
			instrus[itera][1] = 3;
			sizeInicio = 1;
			printf("Sin size al inicio, tamaño por defecto 3\n");
		}
	}else if (strncmp(line, "touch", 5) == 0)
	{
		//printf("touch\n");
		instrus[itera+sizeInicio][0] = 1;

	}
	else if (strncmp(line, "push", 4) == 0)
	{
		//printf("push\n");
		instrus[itera+sizeInicio][0] = 2;
	}
	else if (strncmp(line, "drag", 4) == 0)
	{
		//printf("drag\n");
		tokens = strSplit(line, ' ');
		int y = atoi(*(tokens + 1));
		if (y > 0 && y < 10) {
			instrus[itera+sizeInicio][0] = 3;
    		instrus[itera+sizeInicio][1] = y;
		} else {
			printf("En drag: Rango %d fuera de limites 1-9\n", y);
			sal = -1;
		}

	}
	else if (strncmp(line, "cypher", 6) == 0)
	{
		//printf("cypher\n");
		tokens = strSplit(line, ' ');
		int n = count_tmp - 1;
		int coord;
		instrus[itera+sizeInicio][0] = 4;
		instrus[itera+sizeInicio][1] = n;
		for (int i = 1; i < n; ++i)
		{
			coord = atoi(*(tokens + i));
			if (coord > 0 && coord < 10) {
				instrus[itera][i+1] = coord;
			} else {
				printf("En cypher: Rango %d\n fuera de limites 1-9", coord);
				sal = -1;
				break;
			}


			//printf("Coord: %d ", coord);
		}

		//printf("\n");
	} else {
		printf("Comando erroneo\n");
		sal = -1;
	}

	return sal;

}

void getDataConfig(){
	FILE *archivo;

 	char caracteres[LARGO_LINEA];

 	archivo = fopen("interpreter/configuration","r+");



 	if (archivo == NULL) {
 		printf("Salio\n");
 		exit(1);
 	}

 	int lines = 0;
 	char ch;

 	while (feof(archivo) == 0)
 	{
 		ch = fgetc(archivo);
	    if(ch == '\n')
	    {
	      lines++;
	    }
 	}

 	sizeInstrus = lines;

 	fclose(archivo);

 	int itera_interna = 0;

 	if (lines > 0) {
 		assignedSpace(lines);
	 	archivo = fopen("interpreter/configuration","r+");
	 	int instru_correcta;
	 	for (int i = 0; i < lines; ++i)
	 	{
	 		fgets(caracteres,LARGO_LINEA,archivo);

	 		instru_correcta = getInstruction(caracteres, i - itera_interna);
	 		if (instru_correcta != 0) {
	 			itera_interna++;
	 		}


	 	}

	    fclose(archivo);
 	}


}
