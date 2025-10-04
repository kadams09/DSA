#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    int roll;
    char name[100];
    float marks;
    char gender;
} Student;

typedef struct Node
{
    Student data;
    struct Node *next;
} Node;

Student accept()
{
    Student temp;

    printf("Enter a Student Details:");

    printf("\nRoll Number:");
    scanf("%d", &temp.roll);
    printf("Name:");
    scanf("%s", &temp.name);
    printf("Marks:");
    scanf("%f", &temp.marks);
    printf("Gender:");
    scanf(" %c", &temp.gender);

    return temp;
}
Node *createNode(Student s)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = s;
    return newNode;
}
// Append(Insert Last)
void add(Node **r, Student s)
{
    Node *newNode = createNode(s);

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
// Display single student at a time
void display(Student s)
{
    printf("\n\nRoll Number : %d", s.roll);
    printf("\nName : %s", s.name);
    printf("\nMarks : %f", s.marks);
    printf("\nGender : %c", s.gender);
}
// Search by roll No
Node *searchByRoll(Node *head, int roll)
{
    while (head != NULL)
    {
        if (head->data.roll == roll)
            return head;
        head = head->next;
    }
    return NULL;
}
// search by name
int searchByName(Node *head, char name[100])
{
    int flag = 0;
    while (head != NULL)
    {
        if (stricmp(head->data.name, name) == 0)
        {
            display(head->data);
            flag = 1;
        }
        head = head->next;
    }
    return flag;
}

void topperInBoys(Node *head)
{
    float max = -1;
    Node *temp = head; // Backup

    while (head != NULL)
    {
        if (head->data.gender == 'M' || head->data.gender == 'm')
        {
            max = head->data.marks;
            break;
        }
        head = head->next;
    }
    if (max == -1)
        return;
    head = temp; // restore

    while (head != NULL)
    {
        if (head->data.marks > max && (head->data.gender == 'M' || head->data.gender == 'm'))
            max = head->data.marks;
        head = head->next;
    }
    head = temp; // restore

    while (head != NULL)
    {
        if (head->data.marks == max && (head->data.gender == 'M' || head->data.gender == 'm'))
            display(head->data);
        head = head->next;
    }
}

void topperInGirls(Node *head)
{
    float max = -1;
    Node *temp = head; // Backup
    while (head != NULL)
    {
        if (head->data.gender == 'f' || head->data.gender == 'F')
        {
            max = head->data.marks;
            break;
        }
        head = head->next;
    }
    if (max == -1)
        return;
    head = temp; // restore

    while (head != NULL)
    {
        if (head->data.marks > max && (head->data.gender == 'F' || head->data.gender == 'f'))
            max = head->data.marks;
        head = head->next;
    }
    head = temp; // restore

    while (head != NULL)
    {
        if (head->data.marks == max && (head->data.gender == 'F' || head->data.gender == 'f'))
            display(head->data);
        head = head->next;
    }
}
void fail(Node *head)
{
    while (head != NULL)
    {
        if (head->data.marks < 35)
            display(head->data);
        head = head->next;
    }
}
void deleteByRollNo(Node **r, int roll)
{
    Node *del;

    if ((*r)->data.roll == roll)
    {
        del = (*r);
        (*r) = (*r)->next;
        del->next = NULL;
        free(del);
    }
    else
    {
        Node *temp = (*r);
        while (temp->next->data.roll != roll)
        {
            temp = temp->next;
            break;
        }
        if (temp->next != NULL)
        {
            del = temp->next;
            temp->next = del->next;
            del->next = NULL;
            free(del);
        }
    }
}

void update(Node **r, Student data)
{
    (*r)->data = data;
}

int main()
{
    Node *head = NULL;
    int roll, ch;
    Student s;
    int flag;
    char name[100];
    Node *result;

    while (1)
    {
        printf("\n\n1. Add\n2. Display\n3. search By Roll No.\n4. search By Name\n5.Topper In Boys\n6. Topper in Girls\n7. Fail\n8. Delete By Roll No\n9. update\n10.exit\n enter a choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            s = accept();
            add(&head, s);
            break;
        case 2:
            result = head;
            while (result != NULL)
            {
                display(result->data);
                result = result->next;
            }
            break;

        case 3:
            printf("enter a Roll Number:");
            scanf("%d", &roll);
            result = searchByRoll(head, roll);
            if (result == NULL)
                printf("NOT FOUND !!");
            else
                display(result->data);
            break;

        case 4:
            printf("Enter a Name:");
            scanf("%s", &name);
            flag = searchByName(head, name);
            if (flag == 0)
                printf("NOT FOUND !!");
            break;

        case 5:
            topperInBoys(head);
            break;
        case 6:
            topperInGirls(head);
            break;
        case 7:
            fail(head);
            break;
        case 8:
            printf("Enter a Roll Number:");
            scanf("%d", &roll);
            deleteByRollNo(&head, roll);
            break;
        case 9:
            printf("Enter a Roll Number:");
            scanf("%d", &roll);
            result = searchByRoll(head, roll);
            if (result == NULL)
                printf("NOT FOUND !!");
            else
            {
                printf("Enter New Name:");
                scanf("%s", &s.name);
                printf("Enter a marks:");
                scanf("%f", &s.marks);
                printf("Enter a gender:");
                scanf(" %c", &s.gender);
                s.roll = result->data.roll;
                update(&result, s);
            }
            break;
        case 10:
            exit(0);

        default:
            printf("INVALID CHOICE");
        }
    }
}