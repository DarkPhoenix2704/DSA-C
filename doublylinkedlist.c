#include<stdio.h>

#include<stdlib.h>

void traverse();
void insertFront();
void insertEnd();
void insertAny();
void deleteFront();
void deleteEnd();
void deleteAny();
typedef struct node {
    int data;
    struct node * next, * prev;
}
NODE;
NODE * start = NULL, * newPtr = NULL, * temp, * temp1, * temp2;

void main() {
    int no, item;
    char ch;
    printf("\nProgram to Perform Operations on Singly Linked List");
    printf("\n___________________________________________________");
    do {
        printf("\nMENU");
        printf("\n 1.Traverse");
        printf("\n 2.Insert at FrontEnd");
        printf("\n 3.Insert at End");
        printf("\n 4.Insert at Any Position");
        printf("\n 5.Delete at FrontEnd");
        printf("\n 6.Delete at End");
        printf("\n 7.Delete an Element");
        printf("\n 8.Exit");
        printf("\n\n\nEnter your choice: ");
        scanf("%d", & no);
        switch (no) {
        case 1:
            traverse();
            break;
        case 2:
            insertFront();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            insertAny();
            break;
        case 5:
            deleteFront();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deleteAny();
            break;
        case 8:
            printf("\n\nExiting!!!!!!!!!!");
            return;
        default:
            printf("\n\nInvalid Entry....");
            break;
        }
        printf("\n\n\n Do you want to continue?");
        scanf("%s", & ch);
    } while (ch == 'y' || ch == 'Y');
}
void insertFront() {
    newPtr = (NODE * ) malloc(sizeof(NODE));
    printf("\n\nEnter the element");
    scanf("%d", & newPtr -> data);
    newPtr -> next = NULL;
    newPtr -> prev = NULL;
    if (start == NULL) {
        start = newPtr;
    } else {
        newPtr -> next = start;
        start -> prev = newPtr;
        start = newPtr;
    }
}

void insertEnd() {
    newPtr = (NODE * ) malloc(sizeof(NODE));
    printf("\n\nEnter the element");
    scanf("%d", & newPtr -> data);
    newPtr -> next = NULL;
    newPtr -> prev = NULL;
    if (start == NULL) {
        start = newPtr;
    } else {
        temp = start;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        newPtr -> prev = temp;
        temp -> next = newPtr;

    }
}
void insertAny() {
    int pos, i;
    newPtr = (NODE * ) malloc(sizeof(NODE));
    newPtr -> prev = NULL;
    newPtr -> next = NULL;
    printf("\n\nEnter the element: ");
    scanf("%d", & newPtr -> data);
    printf("\nEnter the position: ");
    scanf("%d", & pos);
    temp = start;
    while (i < pos - 1) {
        temp = temp -> next;
        i++;
    }
    temp1 = temp -> next;
    temp -> next = newPtr;
    newPtr -> prev = temp;
    newPtr -> next = temp1;
}

void traverse() {
    if (start == NULL) {
        printf("\n\nEmpty list");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("\n%d", temp -> data);
            temp = temp -> next;
        }
    }
}
void deleteFront() {
    if (start == NULL) {
        printf("\n\nEmpty List");
    } else {
        temp = start;
        start = start -> next;
        start -> prev = NULL;
        printf("\nDeleted element is %d\n\n", temp -> data);
        free(temp);
    }
}
void deleteEnd() {
    if (start == NULL) {
        printf("\n\nEmpty list");
    } else {
        temp = start;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp1 = temp -> prev;
        printf("\nDeleted item is %d", temp -> data);
        free(temp);
        temp1 -> next = NULL;
    }
}
void deleteAny() {
    int pos, i = 0;
    printf("\n\nEnter the position: ");
    scanf("%d", & pos);
    temp = start;
    while (i < pos - 1) {
        temp = temp -> next;
        i++;
    }
    temp2 = temp -> next;
    temp1 = temp -> prev;
    printf("\n\nDeleted element is %d\t", temp -> data);
    free(temp);
    temp1 -> next = temp2;
    temp2 -> prev = temp1;
}
