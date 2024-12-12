#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
 
#define BUFFER_SIZE 5
 
int buffer[BUFFER_SIZE];  // Buffer compartido
int in = 0, out = 0;      // Índices de entrada y salida
 
sem_t empty;              // Semáforo para espacios vacíos
sem_t full;               // Semáforo para elementos llenos
pthread_mutex_t mutex;    // Mutex para exclusión mutua
 
void* productor(void* arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        item = i;  // Producimos un elemento
        sem_wait(&empty);  // Esperamos un espacio vacío
        pthread_mutex_lock(&mutex);  // Bloqueamos el acceso al buffer
 
        buffer[in] = item;  // Insertamos el elemento en el buffer
        printf("Productor: Insertó el elemento %d en la posición %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
 
        pthread_mutex_unlock(&mutex);  // Liberamos el buffer
        sem_post(&full);  // Incrementamos el número de elementos llenos
        sleep(1);
    }
    return NULL;
}
 
void* consumidor(void* arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        sem_wait(&full);  // Esperamos un elemento lleno
        pthread_mutex_lock(&mutex);  // Bloqueamos el acceso al buffer
 
        item = buffer[out];  // Retiramos el elemento del buffer
        printf("Consumidor: Retiró el elemento %d de la posición %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
 
        pthread_mutex_unlock(&mutex);  // Liberamos el buffer
        sem_post(&empty);  // Incrementamos el número de espacios vacíos
        sleep(1);
    }
    return NULL;
}
 
int main() {
    pthread_t prod, cons;
 
    // Inicializamos los semáforos y el mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
 
    // Creamos los hilos
    pthread_create(&prod, NULL, productor, NULL);
    pthread_create(&cons, NULL, consumidor, NULL);
 
    // Esperamos a que los hilos terminen
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
 
    // Destruimos los semáforos y el mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
 
    return 0;
}
