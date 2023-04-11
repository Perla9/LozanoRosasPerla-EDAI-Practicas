
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
int main(){
 	int i,x;
    struct Stack* stack = createStack(10);
		push(stack, 1);
		push(stack, 2);
		push(stack, 3);
		push(stack, 4);
		push(stack, 5);
		push(stack, 6);
		push(stack, 7);
		push(stack, 8);
		push(stack, 9);
		push(stack, 10);

		printf("Ustes se encuentra en la cola con el turno %d\n",peek(stack));
		printf("El elemento al tope es: %d\n", peek(stack));
		if   (isFull);
		{
			{
			return stack->top == stack->capacity - 1;
			}
			printf("Por el momento ya no hay mas turnos\n");
		}
		
    
}