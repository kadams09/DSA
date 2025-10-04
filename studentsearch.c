#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int roll;
    char name[100];
    float marks;
} student;

typedef struct Node
{
    student s;
    struct Node *next;
} Node;
student accept()
{
    student data;
    printf("Enter a student Details:");

    printf("\nID :");
    scanf("%d", &data.roll);

    printf("Name :");
    scanf("%s", &data.name);

    printf("Marks :");
    scanf("%f", &data.marks);

    return data;
}
void append(Node **r, student data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->s = data;
    newNode->next = NULL;

    if ((*r) == NULL)
    {
        (*r) = newNode;
    }
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
        printf("\nRoll Number :%d", head->s.roll);
        printf("\nName        :%s", head->s.name);
        printf("\nMarks       :%f\n", head->s.marks);

        head = head->next;
    }
}

void insertFirst(Node **r, student data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->s = data;
    newNode->next = *r;
    *r = newNode;
}
Node *search(Node *head, int id)
{
    while (head != NULL)
    {
        if (head->s.roll == id)
            return head;
        head = head->next;
    }
    return NULL;
}

int main()
{
    // student data
    Node *head = NULL;
    int ch, roll;
    student data;
    Node *result;

    while (1)
    {
        printf("1.Append\n2.Display\n3.InsertFirst\n4.Search \n10.EXIT\nEnter a Choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            data = accept();
            append(&head, data);
            break;
        case 2:
            display(head);
            break;
        case 3:
            data = accept();
            insertFirst(&head, data);
            break;

        case 4:
            printf("Enter a roll no:");
            scanf("%d", &roll);
            result = search(head, roll);
            if (result == NULL)
                printf("not found");
            else
            {
                printf("\nRoll Number :%d", result->s.roll);
                printf("\nName        :%s", result->s.name);
                printf("\nMarks       :%f\n",result->s.marks);
            }
            break;
        case 10:
            return 0;
        default:
            printf("INVALID CHOICE !!");
            break;
        }
    }
}







