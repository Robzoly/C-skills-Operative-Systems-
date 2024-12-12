//@robzoly

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TAMANO_ARREGLO 100
#define NUM_HILOS 4

// Estructura para pasar datos a los hilos
typedef struct {
    int inicio;
    int fin;
    int* arreglo;
    long suma_parcial;
} DatosHilo;

// Función que ejecutará cada hilo
void* calcular_suma(void* arg) {
    DatosHilo* datos = (DatosHilo*)arg;
    datos->suma_parcial = 0;
    for (int i = datos->inicio; i < datos->fin; i++) {
        datos->suma_parcial += datos->arreglo[i];
    }
    return NULL;
}

int main() {
    int arreglo[TAMANO_ARREGLO];
    pthread_t hilos[NUM_HILOS];
    DatosHilo datos_hilos[NUM_HILOS];
    long suma_total = 0;

    // Inicializar el arreglo con valores del 1 al TAMANO_ARREGLO
    for (int i = 0; i < TAMANO_ARREGLO; i++) {
        arreglo[i] = i + 1;
    }

    // Dividir el trabajo entre los hilos
    int elementos_por_hilo = TAMANO_ARREGLO / NUM_HILOS;
    for (int i = 0; i < NUM_HILOS; i++) {
        datos_hilos[i].inicio = i * elementos_por_hilo;
        datos_hilos[i].fin = (i == NUM_HILOS - 1) ? TAMANO_ARREGLO : (i + 1) * elementos_por_hilo;
        datos_hilos[i].arreglo = arreglo;
        datos_hilos[i].suma_parcial = 0;

        if (pthread_create(&hilos[i], NULL, calcular_suma, &datos_hilos[i]) != 0) {
            perror("Error al crear el hilo");
            exit(EXIT_FAILURE);
        }
    }

    // Esperar a que los hilos terminen
    for (int i = 0; i < NUM_HILOS; i++) {
        if (pthread_join(hilos[i], NULL) != 0) {
            perror("Error al esperar al hilo");
            exit(EXIT_FAILURE);
        }
        suma_total += datos_hilos[i].suma_parcial;
    }

    printf("La suma total del arreglo es: %ld\n", suma_total);
    
    return 0;
}
