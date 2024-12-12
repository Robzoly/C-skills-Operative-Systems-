#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMERO_DE_HILOS 10

void *imprimir_hola_mundo(void *tid) {
    //Esta función imprime el identificador del hilo y después termina.
    int id = (int)(long)tid;  // Convertir el puntero a un entero
    printf("Hola mundo. Saludos del hilo %d\n", id);
    pthread_exit(NULL);//terminar hilo
}

int main(int argc, char *argv[]) {
    //El programa principal crea 10 hilos y después termina.
    pthread_t hilos[NUMERO_DE_HILOS];
    int estado, i;

    for (i = 0; i < NUMERO_DE_HILOS; i++) {
        printf("Aqui main. Creando hilo %d\n", i);
        estado = pthread_create(&hilos[i], NULL, imprimir_hola_mundo, (void *)(long)i);  // El argumento debe ser un puntero
        if (estado != 0) {
            printf("Ups. pthread_create devolvió el código de error %d\n", estado);
            exit(-1);
        }
    }

    //Esperar a que todos los hilos terminen antes de que el programa principal termine
    for (i = 0; i < NUMERO_DE_HILOS; i++) {
        pthread_join(hilos[i], NULL);//
    }

    return 0;
}

