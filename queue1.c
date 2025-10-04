#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Queue {
    int data[SIZE];
    int front, rear;
} Queue;

int isFull(Queue q) {
    return q.rear == SIZE - 1;
}

int isEmpty(Queue q) {
    return (q.front == -1 && q.rear == -1) || q.front > q.rear;
}

void insert(Queue *p, int num) {
    p->rear++;
    if (p->front == -1)
        p->front++;
    p->data[p->rear] = num;

    
}

int delete(Queue *p) {
    int temp = p->data[p->front];
    if (p->front == p->rear) {
        p->front = p->rear = -1; // reset
    } else {
        p->front++;
    }
    return temp;
}

void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is Empty !!");
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
        printf("%d ", q.data[i]);
}

int main() {
    int ch, num;
    Queue queue;
    queue.front = queue.rear = -1;

    while (1) {
        printf("\n\n1. Insert\n2. Delete\n3. IsEmpty\n4. Peek\n5. Display\n6. EXIT\nEnter a Choice : ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            if (isFull(queue))
                printf("Queue is Full !!");
            else {
                printf("Enter a Data : ");
                scanf("%d", &num);
                insert(&queue, num);
            }
            break;
        case 2:
            if (isEmpty(queue))
                printf("Queue is Empty !!");
            else
                printf("\nDeleted : %d", delete(&queue));
            break;
        case 3:
            if (isEmpty(queue))
                printf("Queue is Empty !!");
            else
                printf("Queue is NOT Empty !!");
            break;
        case 4: // Peek
            if (isEmpty(queue))
                printf("Queue is Empty !!");
            else
                printf("Front element = %d", queue.data[queue.front]);
            break;
        case 5:
            display(queue);
            break;
        case 6:
            exit(0);
        default:
            printf("INVALID CHOICE !!");
            break;
        }
    }
}
