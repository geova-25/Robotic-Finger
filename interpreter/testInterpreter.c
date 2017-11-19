#include "interpreter.h"

int main()
{
 	getDataConfig();

 	int **instrucciones = getInstrus();

 	int n = getSizeInstrus();

 	printf("Instrus size: %d\n", n);

 	for (int i = 0; i < n; ++i)
 	{
 		printf("Codigo de instru: %d\n", instrucciones[i][0]);
 	}


 	return 0;
}