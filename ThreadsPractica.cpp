//@robzoly

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Función que ejecutará cada hilo
void* hilo_funcion(void* arg) {
    int id = *(int*)arg; // Obtener el identificador del hilo
    printf("Hilo %d en ejecución.\n", id);
    return NULL;
}

int main() {
    pthread_t hilos[5];
    int identificadores[5];

    // Crear los hilos
    for (int i = 0; i < 5; i++) {
        identificadores[i] = i + 1; // Asignar un identificador único a cada hilo
        if (pthread_create(&hilos[i], NULL, hilo_funcion, &identificadores[i]) != 0) {
            perror("Error al crear el hilo");
            exit(EXIT_FAILURE);
        }
    }

    // Esperar a que los hilos terminen
    for (int i = 0; i < 5; i++) {
        if (pthread_join(hilos[i], NULL) != 0) {
            perror("Error al esperar al hilo");
            exit(EXIT_FAILURE);
        }
    }

    printf("Todos los hilos han finalizado.\n");

    return 0;
}
