#include "interpreter.h"

int **instrus;

int count_tmp;

int sizeInstrus;

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

void getInstruction(char line[LARGO_LINEA], int itera){
	//printf("cambio de linea%s\n");       line == "bridge1 ="
	char** tokens;
	int *instru_actual;

	if (strncmp(line, "touch", 5) == 0)
	{	
		//printf("touch\n");
		instrus[itera][0] = 1;

	}
	else if (strncmp(line, "push", 4) == 0)
	{
		//printf("push\n");
		instrus[itera][0] = 2;
	}
	else if (strncmp(line, "drag", 4) == 0)
	{
		//printf("drag\n");
		tokens = strSplit(line, ' ');
		int y = atoi(*(tokens + 1));


    	instrus[itera][0] = 3;

    	instrus[itera][1] = y;


	}
	else if (strncmp(line, "cypher", 6) == 0)
	{
		//printf("cypher\n");
		tokens = strSplit(line, ' ');
		int n = count_tmp - 1;
		int coord;
		instrus[itera][0] = 4;
		instrus[itera][1] = n;
		for (int i = 1; i < n; ++i)
		{
			coord = atoi(*(tokens + i));
			instrus[itera][i+1] = coord;

			//printf("Coord: %d ", coord);
		}

		//printf("\n");
	}

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

 	if (lines > 0) {
 		assignedSpace(lines);
	 	archivo = fopen("interpreter/configuration","r+");
	 	for (int i = 0; i < lines; ++i)
	 	{
	 		fgets(caracteres,LARGO_LINEA,archivo);

	 		getInstruction(caracteres, i);
	 	}

	    fclose(archivo);
 	}
   	
 	
}