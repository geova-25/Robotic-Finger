#include "interpreter.h"
#include "roboticFingerCon.h"
#include <string.h>

int main()
{
 	getDataConfig();



 	int **instrucciones = getInstrus();


 	int n = getSizeInstrus();



 	printf("Instrus size: %d\n", n);
 	int codigo;

 	if (n > 0) {
 		char *instru_total = (char*)calloc(n*30,sizeof(char));
	 	char codigo_str[1];
	 	codigo_str[0] = ' ';

	 	for (int i = 0; i < n; ++i)
	 	{
	 		codigo = instrucciones[i][0];


	 		printf("Codigo de instru: %d\n", codigo);

	 		sprintf(codigo_str, "%d", codigo);

	 		strcat(instru_total, codigo_str);

	 		printf("String final temporal: %s\n", instru_total);

	 		if (codigo == 3) {
	 			int coord = instrucciones[i][1];
	 			char coord_str[1];

	 			sprintf(coord_str, "%d", coord);

	 			strcat(instru_total, coord_str);

	 			printf("Coord: %d\n", coord);

	 		} else if (codigo == 4) {
	 			int n = instrucciones[i][1] -1 ;
	 			printf("Tamanio n: %d\n", n);
	 			for (int j = 0; j < n; ++j)
	 			{
	 				int coord_actual = instrucciones[i][j+2];

	 				char coord_str[1];

	 				sprintf(coord_str, "%d", coord_actual);

	 				strcat(instru_total, coord_str);

	 				printf("Coord actual: %d\n", coord_actual);
	 			}
	 		}

	 		strcat(instru_total, ";");

	 	}

	 	printf("El string final es:%s\n", instru_total);
	  sendDataToFinger(instru_total);

 	} else {
 		printf("El archivo esta vacio\n");
 	}	

 	return 0;
}
