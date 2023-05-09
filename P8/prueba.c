#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* before;
};

struct Node* addToEmpty(struct Node* last, int data) {
  if (last != NULL) return last;
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  last = newNode;
  last->next = last;
  last->before = last;

  printf("\n%d se ha agregado a la estructura!\n",data);

  return last;
}

struct Node* addFront(struct Node* last, int data) {
  if (last == NULL) return addToEmpty(last, data);
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = last->next;
  last->next = newNode;
  last->next->before = last;

  printf("\n%d se ha agregado a la estructura!\n",data);

  return last;
}

struct Node* addEnd(struct Node* last, int data) {
  if (last == NULL) return addToEmpty(last, data);
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = last->next;
  last->next->before = newNode;
  last->next = newNode;
  newNode->before = last;
  last = newNode;

  printf("\n%d se ha agregado a la estructura!\n",data);

  return last;
}

struct Node* addAfter(struct Node* last, int data, int item) {
  if (last == NULL) return NULL;

  struct Node *newNode, *p;

  p = last->next;
  do {
    if (p->data == item) {
      newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data = data;
      newNode->next = p->next;
      p->next->before = newNode;

      p->next = newNode;
      newNode->before = p;

      printf("\n%d se ha agregado a la estructura!",data);
      if (p == last) last = newNode;
      return last;
    }

  p = p->next;
  } while (p != last->next);

  printf("\nEl nodo dado no esta presente en la lista");
  return last;
}

void deleteNode(struct Node** last, int key) {
  if (*last == NULL) return;

  if ((*last)->data == key && (*last)->next == *last) {
    free(*last);
    *last = NULL;
    *last = NULL;

    printf("\n%d se ha eliminado a la estructura!",key);

    return;
  }

  struct Node *temp = *last, *d;
  if ((*last)->data == key) {
    while (temp->next != *last) temp = temp->next;

    temp->next = (*last)->next;
    (*last)->next->before = temp;
    free(*last);
    *last = temp;

    printf("\n%d se ha eliminado a la estructura!",key);

  }

  while (temp->next != *last && temp->next->data != key) {
    temp = temp->next;
  }

  if (temp->next->data == key) {
    d = temp->next;
    temp->next = d->next;
    d->next->before = temp;

    printf("\n%d se ha eliminado a la estructura!",key);

    free(d);
  }
}

void traverse(struct Node* last) {
  struct Node* p;

  if (last == NULL) {
    printf("La lista esta vacia");
    return;
  }

  p = last->next;

  printf("\n");
  do {
  printf("-> ");
  printf("%d ", p->data);
  p = p->next;

  } while (p != last->next);
  printf("-> ");
}

int main() {
  struct Node* last = NULL;

  last = addToEmpty(last, 6);
  last = addEnd(last, 8);
  last = addEnd(last, 2);
  


  while(1)
    {
    int op,val, item;
    printf("Secuencia:\n");
    traverse(last);
    printf("\nBienvenido va a realizar una operacion");
    printf("\n1 Insertar\n2 Eliminar\n3 Salir\nIngrese la opcion:");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        printf("\nDonde sea incertar?");
        printf("\n1 Al final\n2 Al principio\n3 Despues de valor");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\nIntroduce valor a agregar: ");
            scanf("%d",&val);
            last = addEnd(last,val);
            traverse(last);
            break;
        case 2:
            printf("\nIntroduce valor a agregar: ");
            scanf("%d",&val);
            last = addFront(last,val);
            traverse(last);
            break;
        case 3:
            printf("\nIntroduce valor a agregar: ");
            scanf("%d",&val);
            printf("Despues de que valor: ");
            scanf("%d",&item);
            last = addAfter(last,val,item);
            traverse(last);
            break;
        default:
            break;
        }
        break;
    case 2:
        printf("\nIntroduce valor a eliminar: ");
        scanf("%d",&val);
        deleteNode(&last,val);
        traverse(last);
        break;
    case 3:
        return 0;
    default:
        break;
    }

    }
  return 0;
}