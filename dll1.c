#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next, *pre;
} Node;

void append(Node **r, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->pre = NULL;

    if ((*r) == NULL)
        (*r) = newNode;

    else
    {
        Node *temp = (*r);
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->pre = temp;
    }
}
void display(Node *head)
{
    while (head != NULL)
    {
        printf("\n%d", head->data);
        head = head->next;
    }
}

void insertFirst(Node **r, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->pre = NULL;

    if ((*r) == NULL)
        (*r) = newNode;

    else
    {
        newNode->next = (*r);
        (*r)->pre = newNode;
        (*r) = newNode;
    }
}

Node *search(Node *r, int data)
{
    while (r != NULL)
    {
        if (r->data == data)
            return r;
        r = r->next;
    }
    return NULL;
}

int count(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void deleteFirst(Node **r)
{
    if ((*r)->next == NULL)
        (*r) = NULL;

    else
    {
        Node *del = (*r);
        (*r) = (*r)->next;
        del->next = NULL;
        (*r)->pre = NULL;
        free(del);
    }
}

void deleteLast(Node **r)

{
    if ((*r)->next == NULL)
        (*r) = NULL;

    else
    {
        Node *temp = (*r);
        while (temp->next->next != NULL)
            temp = temp->next;
        temp->next->pre = NULL;
        temp->next = NULL;
    }
}

void deletebyvalue(Node **r, int data)
{
    Node *temp = *r;
    Node *del;
    while (temp->next->data != data)
    {
        temp = temp->next;
        if (temp->next == NULL)
            return;
    }

    del = temp->next;
    temp->next = del->next;
    del->next = NULL;
    free(del);
}
void insertByPosition(Node **r, int pos, int data)
{
    int i;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *temp = *r;

    for (i = 2; i < pos; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteByPosition(Node *head, int pos)
{
    Node *temp = head, *del;
    int i;

    for (i = 2; i < pos; i++)
        temp = temp->next;

    del = temp->next;
    temp->next = del->next;
    del->next = NULL;
    free(del);
}

int main()
{
    Node *head = NULL;
    Node *temp;
    int ch, data, pos, result;

    while (1)
    {
        printf("\n\n1. Append\n2. Display\n3. InsertFirst\n4. Search\n5. Count\n6. Delete First\n7. Delete Last\n8. Delete By Value\n9. Insert By Position\n10. Delete By Position\n11. Exit\nEnter your choice:");
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
            printf("enter a data:");
            scanf("%d", &data);
            insertFirst(&head, data);
            break;

        case 4:
            printf("enter a data:");
            scanf("%d", &data);
            temp = search(head, data);
            if (temp == NULL)
                printf("NOT FOUND !");
            else
                printf("FOUND !");
            break;

        case 5:
            printf("Count is :%d", count(head));
            break;

        case 6:
            if (head == NULL)
            {
                printf("\nLinked List is empty!!\n");
                continue;
            }
            deleteFirst(&head);
            break;

        case 7:
            if (head == NULL)
            {
                printf("\nLinked list is empty!!");
                continue;
            }
            deleteLast(&head);
            break;
        case 8:
            printf("Enter a Data:");
            scanf("%d", &data);
            if (head->data == data)
                deleteFirst(&head);
            else if (count(head) == 1)
                printf("NOT FOUND !!");
            else
                deletebyvalue(&head, data);
            break;
        case 9:
            printf("Enter a Position :");
            scanf("%d", &pos);
            if (pos > 0 && pos <= count(head) + 1)
            {
                printf("Enter a Data :");
                scanf("%d", &data);
                if (pos == 1)
                    insertFirst(&head, data);
                else if (count(head) + 1 == pos)
                    append(&head, data);
                else
                    insertByPosition(&head, pos, data);
            }
            else
                printf("INVALID POSITION !!");
            break;

        case 10:
            printf("Enter a Position is :");
            scanf("%d", &pos);
            if (pos > 0 && count(head) >= pos)
            {
                if (pos == 1)
                    deleteFirst(&head);
                else if (count(head) == pos)
                    deleteLast(&head);
                else
                    deleteByPosition(head, pos);
            }
            else
                printf("INVALID POSITION !!");
            break;
        case 11:
            return 0;

        default:
            printf("INVALID CHOICE !!");
        }
    }
}