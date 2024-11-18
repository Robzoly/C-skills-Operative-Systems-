//@robzoly

#include <stdio.h>
#include <stdlib.h>


int main(){

	int age = 0;
	int validador = 0;

	printf("Bienvenido a la sala de juegos UNITEC \n");
	printf("----------------------------------------- \n");

	do {
        printf("Ingresa tu edad: ");
        validador = scanf("%d", &age);
	if (validador != 1) {
	            printf("Error: Ingresa un número entero válido.\n");
	            while (getchar() != '\n');
		}
	} while (validador != 1);

	if (age<0) {
        printf("Error: Ingresa un número válido. \n");
	}else if (age<=4){
	printf("El precio de entrada es gratis \n");
	} else if (age<=18){
	printf("Tu precio de entrada es de $5 \n");
	}else if (age<=99){
	printf("Tu precio de entrada es de $10 \n");
	}else{
	printf("Ingrese una edad válida \n");
	}
	
return 0;
}
