//@robzoly

#include <stdio.h>
#include <stdlib.h>

int main(){

	float renta = 0.0;
	float resultado = 0.0;
	int validador= 0;

	printf("Bienvenido al sistema de declaración de rentas \n");
	printf("............................................... \n");

	do {
        printf("Ingrese el valor de su renta para su declaración: ");
        validador = scanf("%f", &renta);

        if (validador != 1) {
            	printf("Error: Ingrese un número válido.\n");
            	while (getchar() != '\n');
        	}
    	} while (validador != 1);


	if (renta < 0.0){
		printf("Ingrese un número válido a su renta. \n");
	}else if (renta < 10000.00) {
		resultado= renta * 0.05;
		printf("A rentas menores a $10,000.00 les corresponde un impositivo del 5%% \n");
		printf("Se debe pagar un total de %f \n", resultado);
	}else if (renta <= 20000.00){
		resultado = renta * 0.15;
		printf("A rentas de $10,000.00 a $20,000.00 les corresponde un impositivo del 15%% \n");
		printf("Se debe pagar un total de %f \n", resultado);
	}else if (renta <= 35000.00){
		resultado = renta * 0.20;
                printf("A rentas de $20,000.01 a $35,000.00 les corresponde un impositivo del 20%% \n");
                printf("Se debe pagar un total de %f \n", resultado);
	}else if (renta <= 60000.00){
		resultado = renta * 0.30;
                printf("A rentas de $35,000.01 a $60,000.00 les corresponde un impositivo del 30%% \n");
                printf("Se debe pagar un total de %f \n", resultado);
	}else{
		resultado = renta * 0.45;
                printf("A rentas mayores a $60,000.00 les corresponde un impositivo del 45%% \n");
                printf("Se debe pagar un total de %f \n", resultado);
	}


return 0;

}


