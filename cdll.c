#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *pre;
} Node;

void append(Node **r, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->pre = NULL;

    if (*r == NULL) {
        *r = newNode;
        newNode->next = newNode->pre = *r;
    } else {
        Node *temp = (*r)->pre;
        newNode->next = *r;
        newNode->pre = temp;
        temp->next = newNode;
        (*r)->pre = newNode;
    }
}

void display(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertfirst(Node **r, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (*r == NULL) {
        *r = newNode;
        newNode->next = newNode->pre = *r;
    } else {
        (*r)->pre->next = newNode;
        newNode->pre = (*r)->pre;
        newNode->next = *r;
        (*r)->pre = newNode;
        *r = newNode;
    }
}

void deletefirst(Node **r) {
    if (*r == NULL) return;

    Node *del = *r;
    if ((*r)->next == *r) { // only one node
        *r = NULL;
    } else {
        (*r)->pre->next = (*r)->next;
        (*r)->next->pre = (*r)->pre;
        *r = (*r)->next;
    }
    free(del);
}

void deletelast(Node **r) {
    if (*r == NULL) return;

    Node *del = (*r)->pre;
    if ((*r)->next == *r) {
        *r = NULL;
    } else {
        del->pre->next = *r;
        (*r)->pre = del->pre;
    }
    free(del);
}

Node *search(Node *r, int data) {
    if (r == NULL) return NULL;

    Node *temp = r;
    do {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    } while (temp != r);
    return NULL;
}

int count(Node *head) {
    if (head == NULL) return 0;

    int cnt = 0;
    Node *temp = head;
    do {
        cnt++;
        temp = temp->next;
    } while (temp != head);
    return cnt;
}

void insertbyposition(Node *head, int data, int pos) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    Node *temp = head;
    for (int i = 2; i < pos; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->pre = temp;
    temp->next->pre = newNode;
    temp->next = newNode;
}

void deletebyposition(Node *head, int pos) {
    Node *temp = head;
    for (int i = 2; i < pos; i++)
        temp = temp->next;

    Node *del = temp->next;
    temp->next = del->next;
    del->next->pre = temp;
    free(del);
}

void deletebyvalue(Node **r, int data) {
    Node *temp = search(*r, data);
    if (temp == NULL) return;

    if (temp == *r) {
        deletefirst(r);
    } else if (temp == (*r)->pre) {
        deletelast(r);
    } else {
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    int ch, pos, data;
    Node *temp;

    while (1) {
        printf("\n\n1. Append\n2. Display\n3. Insertfirst\n4. Deletefirst\n5. Deletelast\n6. Search\n7. Count\n8. Insert By Position\n9. Delete by position\n10. Delete By Value\n11. EXIT\nEnter a choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            insertfirst(&head, data);
            break;
        case 4:
            deletefirst(&head);
            break;
        case 5:
            deletelast(&head);
            break;
        case 6:
            if (head == NULL) {
                printf("Linked list is empty!\n");
                break;
            }
            printf("Enter data: ");
            scanf("%d", &data);
            temp = search(head, data);
            if (temp == NULL)
                printf("NOT FOUND!\n");
            else
                printf("FOUND!\n");
            break;
        case 7:
            printf("Count = %d\n", count(head));
            break;
        case 8:
            if (head == NULL) {
                printf("Linked list is empty!\n");
                break;
            }
            printf("Enter position: ");
            scanf("%d", &pos);
            if (pos >= 1 && pos <= count(head) + 1) {
                printf("Enter data: ");
                scanf("%d", &data);
                if (pos == 1)
                    insertfirst(&head, data);
                else if (pos == count(head) + 1)
                    append(&head, data);
                else
                    insertbyposition(head, data, pos);
            } else
                printf("INVALID POSITION!\n");
            break;
        case 9:
            if (head == NULL) {
                printf("Linked list is empty!\n");
                break;
            }
            printf("Enter position: ");
            scanf("%d", &pos);
            if (pos == 1)
                deletefirst(&head);
            else if (pos == count(head))
                deletelast(&head);
            else if (pos > 1 && pos < count(head))
                deletebyposition(head, pos);
            else
                printf("INVALID POSITION!\n");
            break;
        case 10:
            if (head == NULL) {
                printf("Linked list is empty!\n");
                break;
            }
            printf("Enter value: ");
            scanf("%d", &data);
            deletebyvalue(&head, data);
            break;
        case 11:
            return 0;
        default:
            printf("INVALID CHOICE!!\n");
        }
    }
}
