//@Robzoly

#include <stdlib.h>
#include <stdio.h>

#define MAX 10

struct queue {
	int items[MAX];
	int front;
	int rear;
};

typedef struct queue qt;

void createEmptyQueue(qt *q){
	q->front = -1;
	q->rear = -1;
}

int isfull(qt *q){
	return q->rear == MAX-1;
}

int isempty(qt *q){
	return q->front == -1 || q->front > q->rear;
}

void enqueue(qt *q, int newitem) {
	if (isfull(q)) {
		printf("La cola está llena\n");
	}else{
		if (q->front == -1){
			q->front = 0;
		}
	q->rear++;
	q->items[q->rear] = newitem;
	printf("Elemento %d agregado a la cola\n", newitem);
	}
}

void dequeue (qt *q) {
	if(isempty(q)){
		printf("\nLa cola está vacía\n");
	}else{
		printf("Elemento eliminado: %d\n", q->items[q->front]);
		q->front++;
		if(q->front > q->rear){
		q->front = -1;
		q->rear = -1;
		}
	}

}

void display(qt *q){
	if (isempty(q)){
		printf("\nLa cola está vacía\n");
	} else {
		printf("\nElementos de la cola: \n");
		for (int i = q->front; i<=q->rear; i++){
		printf("%d ", q->items[i]);
		}
	printf("\n");
	}
}

int main() {
    qt cola;
    createEmptyQueue(&cola);

    int opcion, valor;

    do {
        printf("\nMenú:\n");
        printf("1.- Agregar\n");
        printf("2.- Mostrar\n");
        printf("3.- Eliminar\n");
        printf("4.- Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a agregar: ");
                scanf("%d", &valor);
                enqueue(&cola, valor);
                break;
            case 2:
                display(&cola);
                break;
            case 3:
                dequeue(&cola);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}

