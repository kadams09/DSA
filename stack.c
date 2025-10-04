#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct Stack
{
    int data[SIZE];
    int top;
} Stack;

int isFull(Stack s)
{
    return s.top == SIZE - 1;
}

int isEmpty(Stack s)
{
    return s.top == -1;
}

void push(Stack *p, int num)
{
    p->top++; //-1 to 0
    p->data[p->top] = num;
}

int pop(Stack *p)
{c
    int temp = p->data[p->top];
    p->top--;
    return temp;
}

int peek(Stack s)
{
    return s.data[s.top];
}

int main()
{
    Stack s;
    int ch, num;
    s.top = -1;

    while (1)
    {
        printf("\n\n1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. Peek\n6. EXIT\nEnter a Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (isFull(s))
                printf("\nStack is OverFlow\n");
            else
            {
                printf("Enter a Data : ");
                scanf("%d", &num);
                push(&s, num);
            }
            break;
        case 2:
            if (isEmpty(s))
                printf("Stack is Under Flow");
            else
                printf("\nPop : %d", pop(&s));
            break;
        case 3:
            if (isEmpty(s))
                printf("\nStack is Under Flow\n");
            else
                printf("\nStack is Not Under Flow\n");
            break;
        case 4:
            if (isFull(s))
                printf("\nStack is Over Flow\n");
            else
                printf("\nStack is Not Over Flow\n");
            break;
        case 5:
            if (isEmpty(s))
                printf("\nStack is Under Flow\n");
            else
                printf("Peek : %d", peek(s));
            break;
            case 6: 
            exit(0);
        default:
            printf("INVALID CHOICE !!");
        }
    }
}