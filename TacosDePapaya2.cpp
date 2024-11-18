//@robzoly

#include <stdio.h>
#include <stdlib.h>

int main(){


	char Character;
	char Name[64];

	printf("Ingresa un caracter: \n");
	scanf("%c \n", &Character);

	printf("Ingresa tu nombre: \n");
	scanf("%s \n", Name);

	printf("%c, %s \n", Character, Name);

return 0;
}

