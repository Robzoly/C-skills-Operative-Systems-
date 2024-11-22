//@Robzolyx

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Función factorial
int Factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * Factorial(n - 1);
}

//Función sumatoria
double Sumatoria(int n) {
    double res = 0.0;
    for (int i = 1; i <= n; i++) {
        res += 1.0 / pow(i, n); // pow de <math.h> para potencia
    }
    return res;
}

//Función condición
void Condicion() {
    for (int i = 1000; i <= 9999; i++) {
        int d1 = (i / 1000) % 10; // Dígito 1
        int d2 = (i / 100) % 10;  // Dígito 2
        int d3 = (i / 10) % 10;   // Dígito 3
        int d4 = i % 10;          // Dígito 4

        int sumaImpares = d1 + d3;
        int sumaPares = d2 + d4;

        if (sumaImpares == sumaPares) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int num = 0, opcion = 0;

    do {
        printf("\nBienvenidos al circo digital.\n");
        printf("1.- Factoriales\n");
        printf("2.- Sumatoria\n");
        printf("3.- Impares\n");
        printf("4.- Salir...\n");
        printf("Seleccione una opción: \n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el número factorial que desea conocer: \n");
                scanf("%d", &num);
                printf("El valor factorial de %d es: %d\n", num, Factorial(num));
                break;
            case 2:
                printf("Ingrese el número de la sumatoria: \n");
                scanf("%d", &num);
                printf("El resultado de la sumatoria de %d es: %.6f\n", num, Sumatoria(num));
                break;
            case 3:
                printf("Números de 4 cifras que cumplen con la condición: \n");
                Condicion();
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("OPCIÓN INVÁLIDA, POR FAVOR INTENTE DE NUEVO >:(\n");
        }
    } while (opcion != 4);

    return 0;
}

