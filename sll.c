#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void append(Node **r, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if ((*r) == NULL)
        (*r) = newNode;

    else
    {
        Node *temp = (*r);
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}
void insertFirst(Node **r, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = (*r);
    (*r) = newNode;
}

int count(Node *head)
{
    int cnt = 0;
    while (head)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void insertInBetween(Node *head, int pos, int data)
{
    int i;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *temp = head;

    for (i = 2; i < pos; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst(Node **r)
{
    if (*r == NULL)
    {
        printf("List is already empty!\n");
        return;
    }
    Node *del = *r;
    *r = (*r)->next;
    del->next = NULL;
    free(del);
}
void deleteLast(Node **r)
{
    if (*r == NULL)
    {
        printf("List is already empty!\n");
        return;
    }
}

void deleteInBetween(Node *head, int pos)
{
    int i;
    Node *del;
    Node *temp = head;

    for (i = 2; i < pos; i++)
        temp = temp->next;

    del = temp->next;
    temp->next = del->next;
    del->next = NULL;
    free(del);
}

int getPosition(Node *head, int data)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        if (head->data == data)
            return cnt;
        head = head->next;
    }
    if (head == NULL)
        return -1;
    return cnt;
}

int main()
{
    Node *head = NULL;
    int ch;
    int data, pos;

    while (1)
    {
        printf("\n\n1.Append\n2.Display\n3.InsertFirst\n4.count\n5.InsertInBetween\n6.DeleteFirst\n7.Deletelast\n8.DeleteByPosition\n9.Delete By Value\n10.EXIT\nEnter a choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter a Data:");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter a Data:");
            scanf("%d", &data);
            insertFirst(&head, data);
            break;
        case 4:
            printf("\nCount is: %d", count(head));
            break;
        case 5:
            printf("Enter a position:");
            scanf("%d", &pos);
            printf("Enter a Data:");
            scanf("%d", &data);

            if (pos == 1)
                insertFirst(&head, data);
            else if (pos == count(head) + 1)
                append(&head, data);
            else if (pos > 1 && pos <= count(head))
                insertInBetween(head, pos, data);
            else
                printf("INVALID POSITION !!");
            break;
        case 6:
            if (head == NULL)
                printf("\n Linked List is empty!!");
            else
                deleteFirst(&head);
            break;
        case 7:
            deleteLast(&head);
            break;
        case 8:
            printf("enter a position:");
            scanf("%d", &pos);
            if (pos == 1)
                deleteFirst(&head);
            else if (pos == count(head))
                deleteLast(&head);
            else if (pos > 1 && pos < count(head))
                deleteInBetween(head, pos);
            else
                printf("Invalid Position !!");
            break;
        case 9:
            printf("enter a data:");
            scanf("%d", &data);
            pos = getPosition(head, data);
            if (pos == 1)
                deleteFirst(&head);
            else if (pos == count(head))
                deleteLast(&head);
            else if (pos > 1 && pos < count(head))
                deleteInBetween(head, pos);
            else
                printf("value Not Found !!");
            break;

        case 10:
            return 0;
        default:
            printf("INVALID CHOICE !!");
        }
    }
}