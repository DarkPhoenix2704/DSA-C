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
    struct node * link;
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
        printf("\n\n\n Do you want to continue? ");
        scanf("%s", & ch);
    } while (ch == 'y' || ch == 'Y');
}
void insertFront() {
    newPtr = (NODE * ) malloc(sizeof(NODE));
    printf("\n\nEnter the element: ");
    scanf("%d", & newPtr -> data);
    newPtr -> link = NULL;
    if (start == NULL) {
        start = newPtr;
    } else {
        newPtr -> link = start;
        start = newPtr;
    }
}

void insertEnd() {
    newPtr = (NODE * ) malloc(sizeof(NODE));
    printf("\n\nEnter the element: ");
    scanf("%d", & newPtr -> data);
    newPtr -> link = NULL;
    if (start == NULL) {
        start = newPtr;
    } else {
        temp = start;
        while (temp -> link != NULL) {
            temp = temp -> link;
        }
        temp -> link = newPtr;
    }
}
void insertAny() {
    int pos, i;
    newPtr = (NODE * ) malloc(sizeof(NODE));
    printf("\n\nEnter the element: ");
    scanf("%d", & newPtr -> data);
    printf("\nEnter the position: ");
    scanf("%d", & pos);
    temp = start;
    while (i < pos - 1) {
        temp = temp -> link;
        i++;
    }
    temp1 = temp -> link;
    temp -> link = newPtr;
    newPtr -> link = temp1;
}

void traverse() {
    if (start == NULL) {
        printf("\n\nEmpty list");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("\n%d", temp -> data);
            temp = temp -> link;
        }
    }
}
void deleteFront() {
    if (start == NULL) {
        printf("\n\nEmpty List");
    } else {
        temp = start;
        start = start -> link;
        printf("\nDeleted element is %d\n\n", temp -> data);
        free(temp);
    }
}
void deleteEnd() {
    if (start == NULL) {
        printf("\n\nEmpty list");
    } else {
        temp = start;
        while (temp -> link != NULL) {
            temp1 = temp;
            temp = temp -> link;
        }
        printf("\nDeleted item is %d", temp -> data);
        free(temp);
        temp1 -> link = NULL;
    }
}
void deleteAny() {
    int pos, i = 0;
    printf("\n\nEnter the position: ");
    scanf("%d", & pos);
    temp = start;
    while (i < pos - 1) {
        temp1 = temp;
        temp = temp -> link;
        i++;
    }
    temp2 = temp -> link;
    temp1 -> link = temp2;
    printf("\nDeleted item is: %d", temp -> data);
    free(temp);
}
