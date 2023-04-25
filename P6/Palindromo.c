#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


// Una estructura que representa una cola
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// Funcion para crear una cola dada una capacidad. Inicia su tamaño de
// cola como 0
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

// La cola esta llena cuando se vuelve
// igual a la capacidad
int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

// La cola esta vacia cuando su tamano es cero
int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

// Funcion para agregar un elemento a la cola.
// Cambia la parte trasera y el tamano.
void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
}

// Funcion para eliminar un elemento de la cola.
// Cambia el frente y el tamano.
int dequeueFront(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

int dequeueRear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->rear];
	queue->rear = (queue->rear - 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Funcion para obtener el frente de la cola.
int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Funcion para obtener la parte trasera de la cola
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

// Funcion principal para probar las operaciones.
int main()
{
	struct Queue* queue = createQueue(30);
	char palabra[20];
	int i,a,b,palindromo;

	i=0;
	printf("Bienvenido al Revisor de Palabras\n");
	printf("Ingrese la palabra: ");
	scanf("%s",palabra);

	while(palabra[i]!='\0')
    {
        enqueue(queue,(palabra[i]));
        i++;
    }

	palindromo=1; a=1; b=1;
	while(a!=INT_MIN && b!=INT_MIN)
    {
        a=dequeueRear(queue);
        b=dequeueFront(queue);
        if(b==INT_MIN)
        {break;}
        if(a!=b)
        {
            palindromo=0;
            break;
        }
    }

    if(palindromo==1)
    {
        printf("La palabra... Es palindromo!\n");
    }
    else
    {
        printf("La palabra... No es aplindromo!\n");
    }

	return 0;
}