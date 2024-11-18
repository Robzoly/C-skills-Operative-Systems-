//@robzoly

#include <stdio.h>
#include <stdlib.h>

int main(){

/*
	int x=10;
	printf("%d \n", x);
*/


	int x=0;
	int y=0;
	float f=0.0;

	printf("Ingresa un número: \n");
	scanf("%d \n", &x); //ingresa en el tipo de variable que se declara.

	printf("Ingresa un segundo número: \n");
	scanf("%d \n", &y);

	printf("Los números ingresados son: %d y %d \n", x, y);

	printf("Ingresa un número decimal: \n");
	scanf("%f", &f);
	printf("El tipo floar es: %f", f);

return 0;
}
