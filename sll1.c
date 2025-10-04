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

void insertFirst(Node **r, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = (*r);
    (*r) = newNode;
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("\n%d", head->data);
        head = head->next;
    }
}
int search(Node *head, int data)
{
    int index = 1;
    while (head != NULL)
    {
        if (head->data == data)
            return index;
        head = head->next;
        index++;
    }
    return (head == NULL) ? -1 : index;
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
    Node *del;
    if ((*r) == NULL)
        return;

    del = (*r);
    (*r) = (*r)->next;
    del->next = NULL;
    free(del);
}

void deleteLast(Node **r)
{

    if ((*r) == NULL)
        return;
    if ((*r)->next == NULL){
        free(*r);
        *r = NULL;
    }
    else
    {
        Node *temp = (*r);
        while (temp->next->next != NULL)
            temp = temp->next;
        temp->next = NULL;
    }
}

void insertByPosition(Node *head, int pos, int data)
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

void deleteByValue(Node *head, int data)
{

    Node *temp = head;
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
int main()
{
    Node *head = NULL;
    int ch, data, pos, result;

    while (1)
    {
        printf("\n\n1.Append\n2.Insert First\n3.Display\n4.Count\n5.Search\n6.Delete First\n7.Delete Last\n8.Delete By Position\n9.Delete By Value\n10.Insert By Position \n11.EXIT\nEnter a choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter a Data :");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 2:
            printf("Enter a Data :");
            scanf("%d", &data);
            insertFirst(&head, data);
            break;
        case 3:
            display(head);
            break;
        case 4:
            printf("Count is %d", count(head));
            break;
        case 5:
            printf("Enter a Data :");
            scanf("%d", &data);
            result = search(head, data);
            if (result != -1)
                printf("FOUND at %d", result);
            else
                printf("NOT FOUND !!");
            break;

        case 6:
            deleteFirst(&head);
            break;
        case 7:
            deleteLast(&head);
            break;

        case 8:
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
        case 9:
            printf("Enter a Data :");
            scanf("%d", &data);
            if (head->data == data)
                deleteFirst(&head);
            else if (count(head) == 1)
                printf("NOT FOUND!!");
            else
                deleteByValue(head, data);
            break;

        case 10:
            printf("Enter a Data :");
            scanf("%d", &data);
            if (pos > 0 &&  pos <= count(head) + 1 )
            {
                printf("Enter a Data :");
                scanf("%d", &data);
                if (pos == 1)
                    insertFirst(&head, data);
                else if (count(head) + 1 == pos)
                    append(&head, data);
                else
                    insertByPosition(head, pos, data);
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
