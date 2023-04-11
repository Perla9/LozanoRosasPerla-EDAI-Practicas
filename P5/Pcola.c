#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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
	
}
int main()
{
	struct Queue* queue = createQueue(10);

	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);

	printf("El elemento de al final en la cola es es: %d\n", rear(queue));

	return 0;
}