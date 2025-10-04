#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;

} Node, Stack;
int isEmpty(Node const *top)
{
    return top == NULL;
}

void push(Node **r,int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty((*r)))
        (*r) = newNode;
    else
    {

        newNode->next = (*r);
        (*r) = newNode;
    }
}
int pop(Node **r)
{
    Node *del = (*r);
    int temp = del->data;
    (*r) = (*r)->next;
    del->next = NULL;
    free(del);
    return temp;
}

int peek(Node const *top)
{
    return top->data;
}

int main()
{
    int ch, data;
    Stack *top = NULL;
    while (1)
    {
        printf("\n\n1. Push\n2. Pop\n3. IsEmpty\n4. Peek\n5. EXIT\nEnter a Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data :");
            scanf("%d", &data);
            push(&top, data);
            break;

        case 2:
            if (isEmpty(top))
                printf("Stack is Under Flow");
            else
                printf("\nPop : %d", pop(&top));
            break;
        case 3:
            if (isEmpty(top)){
                printf("\nStack is Under Flow\n");
            }
            else
                printf("\nStack is Not Under Flow\n");
            break;
        case 4:
            if (isEmpty(top))
                printf("\nStack is Under Flow\n");
            else
                printf("PEEK : %d",peek(top));
            break;
        case 5:
            exit(0);
        default:
            printf("INVALID CHOICE !!");
        }
    }
}