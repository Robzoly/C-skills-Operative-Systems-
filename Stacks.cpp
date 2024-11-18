//Robzoly

#include <stdlib.h>
#include <stdio.h>

#define MAX 10 // Tamaño máximo de la pila

int count = 0;

// Estructura de la pila
struct stack {
    int items[MAX];
    int top;
};

typedef struct stack st;

// Inicializa una pila vacía
void createEmptyStack(st *s) {
    s->top = -1;
}

// Verifica si la pila está llena
int isfull(st *s) {
    return s->top == MAX - 1;
}

// Verifica si la pila está vacía
int isempty(st *s) {
    return s->top == -1;
}

// Agrega un elemento a la pila
void push(st *s, int newitem) {
    if (isfull(s)) {
        printf("La pila está llena\n");
    } else {
        s->top++;
        s->items[s->top] = newitem;
        count++;
        printf("Elemento %d agregado a la pila\n", newitem);
    }
}

// Elimina un elemento de la pila
void pop(st *s) { 
    if (isempty(s)) { 
        printf("\nLa pila está vacía\n");
    } else {
        printf("Elemento eliminado: %d\n", s->items[s->top]);
        s->top--;
        count--;
    }
}

// Muestra los elementos de la pila
void display(st *s) {
    if (isempty(s)) {
        printf("\nLa pila está vacía\n");
    } else {
        printf("\nElementos de la pila:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);
        }
    }
}

// Función principal con el menú
int main() {
    st pila;
    createEmptyStack(&pila);

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
                push(&pila, valor);
                break;
            case 2:
                display(&pila);
                break;
            case 3:
                pop(&pila);
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


