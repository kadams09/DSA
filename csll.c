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
    if (*r == NULL)
    {
        *r = newNode;
        newNode->next = newNode; 
    }
    else
    {
        newNode->next = (*r)->next;
        (*r)->next = newNode;
        *r = newNode; 
    }
}

void display(Node *r)
{
    if (r == NULL)
    {
        printf("\nList is empty!");
        return;
    }
    Node *temp = r->next; 
    
    {
        printf(" %d", temp->data);
        temp = temp->next;
    } while (temp != r->next);
}

void insertFirst(Node **r, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (*r == NULL)
    {
        *r = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = (*r)->next;
        (*r)->next = newNode;
    }
}

int search(Node *r, int data)
{
    if (r == NULL)
        return 0;
    int index = 1;
    Node *temp = r->next;
    {
        if (temp->data == data)
            return index;
        temp = temp->next;
        index++;
    } while (temp != r->next);
    return 0;
}

int count(Node *r)
{
    if (r == NULL)
        return 0;
    int cnt = 0;
    Node *temp = r->next;
    {
        cnt++;
        temp = temp->next;
    } while (temp != r->next);
    return cnt;
}

void deleteFirst(Node **r)
{
    if (*r == NULL)
        return;

    Node *head = (*r)->next;
    if (*r == head)
    { 
        free(*r);
        *r = NULL;
    }
    else
    {
        (*r)->next = head->next;
        free(head);
    }
}

void deleteLast(Node **r)
{
    if (*r == NULL)
        return;

    Node *head = (*r)->next;
    if (head == *r)
    { 
        free(*r);
        *r = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next != *r)
            temp = temp->next;
        temp->next = (*r)->next;
        free(*r);
        *r = temp; 
    }
}

void insertByPosition(Node **r, int pos, int data)
{
    int n = count(*r);
    if (pos < 1 || pos > n + 1)
    {
        printf("\nInvalid Position!");
        return;
    }

    if (pos == 1)
    {
        insertFirst(r, data);
        return;
    }
    if (pos == n + 1)
    {
        append(r, data);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *temp = (*r)->next;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(Node **r, int data)
{
    if (*r == NULL)
        return;

    Node *head = (*r)->next;
    Node *temp = head;

    
    {
        if (temp->next->data == data)
        {
            Node *del = temp->next;
            if (del == *r)
                *r = temp; 
            if (del == *r && del == head)
            { 
                *r = NULL;
            }
            else
            {
                temp->next = del->next;
            }
            free(del);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("\nValue not found!");
}

int main()
{
    Node *rear = NULL;
    int data, ch, pos, result;

    while (1)
    {
        printf("\n\n1.Append\n2.Display\n3.Insert First\n4.Search\n5.Count\n6.Delete First\n7.Delete Last\n8.Insert By Position\n9.Delete By Value\n10.Exit\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d", &data);
            append(&rear, data);
            break;
        case 2:
            display(rear);
            break;
        case 3:
            printf("Enter Data: ");
            scanf("%d", &data);
            insertFirst(&rear, data);
            break;
        case 4:
            printf("Enter Data: ");
            scanf("%d", &data);
            result = search(rear, data);
            if (result)
                printf("Found at %d", result);
            else
                printf("Not Found");
            break;
        case 5:
            printf("Count = %d", count(rear));
            break;
        case 6:
            deleteFirst(&rear);
            break;
        case 7:
            deleteLast(&rear);
            break;
        case 8:
            printf("Enter Position: ");
            scanf("%d", &pos);
            printf("Enter Data: ");
            scanf("%d", &data);
            insertByPosition(&rear, pos, data);
            break;
        case 9:
            printf("Enter Data: ");
            scanf("%d", &data);
            deleteByValue(&rear, data);
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid Choice!");
        }
    }
}
