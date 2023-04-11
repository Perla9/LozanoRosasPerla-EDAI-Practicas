
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}
int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}
void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%d push a la pila\n", item);
}
int peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue
		= (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// Esto es importante ver en operacion encolar
	queue->rear = capacity - 1;
	queue->array
		= (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}
int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}
int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}
void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d agregado a la cola\n", item);
}
int main(){
 	int i,x;
    struct Stack* stack = createStack(10);
    struct Queue* queue = createQueue(10);
		push(stack, 1);
        enqueue(queue, 1);
		push(stack, 2);
        enqueue(queue, 2);
		push(stack, 3);
        enqueue(queue, 3);
		push(stack, 4);
        enqueue(queue, 4);
		push(stack, 5);
        enqueue(queue, 5);
		push(stack, 6);
        enqueue(queue, 6);
		push(stack, 7);
        enqueue(queue, 7);
		push(stack, 8);
        enqueue(queue, 8);
		push(stack, 9);
        enqueue(queue, 9);
		push(stack, 10);
        enqueue(queue, 10);

		printf("Ustes se encuentra en la cola con el turno %d\n",peek(stack));
		printf("El elemento al tope es: %d\n", peek(stack));
        printf("El elemento de al final en la cola es es: %d\n", rear(queue));
		if   (isFull);
		{
			{
			return stack->top == stack->capacity - 1;
			}
			printf("Por el momento ya no hay mas turnos\n");
		}
	
	return 0;
    
}

void menu(){ 
    struct Stack* stack = createStack(10); 
    char opc;
    while (1){
        printf("\n\tBienvenido al sistema de turnos\n");
        printf("Elija una opción\n");
        printf("1) Formarse\n");
        printf("2) Salir.\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:{
            pila();
            printf("Usted se encuentra formado en la cola su turno es el %d\n", i+1);
                if pila isFull(struct Stack* stack);
                    return stack->top == stack->capacity - 1;
                    printf("Ya no hay turnos disponibles");
            break;
        }
        case 2:
        {
            return 0;
        }
        default:{
             printf("Opcion invalida");
            }
        }
    } 
	return 0;
}
