//@robzoly

#include <stdio.h>
#include <stdlib.h>

int main() {
    float nivel= 0.0;
    float res=0.0;
    int validador;

    printf("Bienvenido al programa evaluador de empleados\n");
    printf("................................................\n");

    do {
        printf("Tabla de desempeño de los empleados\n");
        printf("Inaceptable: 0.0\n");
        printf("Aceptable: 0.4\n");
        printf("Meritorio: 0.6 o más\n");
        printf("Ingrese el valor de desempeño de sus empleados en base a la tabla: ");

        validador = scanf("%f", &nivel);

        if (validador != 1) {
            printf("Error: Ingrese un valor numérico válido.\n");
            while (getchar() != '\n'); 
        }
    } while (validador != 1);

    if (nivel < 0.0) {
        printf("Error: El nivel de desempeño no puede ser negativo.\n");
    } else if (nivel < 0.6 && nivel != 0.0 && nivel != 0.4) {
        printf("El nivel de desempeño debe ser 0.0, 0.4 o 0.6 o más.\n");
    } else {
        res = 2400.00 * nivel;
        if (nivel == 0.0) {
            printf("El desempeño del empleado ha sido INACEPTABLE. El bono es: $%f\n", res);
        } else if (nivel == 0.4) {
            printf("El desempeño del empleado ha sido ACEPTABLE. El bono es: $%f\n", res);
        } else {
            printf("El desempeño del empleado ha sido MERITORIO. El bono es: $%f\n", res);
        }
    }

    return 0;
}
