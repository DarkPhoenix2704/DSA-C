#include<stdio.h>

#include<stdlib.h>

void traverse();
void insertfront();
void insertend();
void insertany();
void deletefront();
void deleteend();
void deleteany();
typedef struct node {
    int data;
    struct node * link;
}
NODE;
NODE * header = NULL, * newptr = NULL, * ptr, * ptr1;
void main() {
    int no, item;
    char c;
    printf("\n\tPROGRAM TO PERFORM OPERATIONS ON SINGLE LINKED LIST");
    printf("\n\t.......................................................");
    do {
        printf("\n\t\t\t\tMENU\n\n");
        printf("\t\t1.TRAVERSE\n\t\t2.INSERT AT FRONT\n\t\t3.INSERT AT END\n\t\t4.INSERT AT ANY POSITION\n\t\t5.DELETE FROM FRONT\n\t\t6.DELETE FROM END\n\t\t7.DELETE FROM ANY POSITION\n\t\t8.EXIT\n\t\tEnter your choice: ");
        scanf("%d", & no);
        if (no == 8)
            break;
        switch (no) {
        case 1:
            traverse();
            break;
        case 2:
            insertfront();
            break;
        case 3:
            insertend();
            break;
        case 4:
            insertany();
            break;
        case 5:
            deletefront();
            break;
        case 6:
            deleteend();
            break;
        case 7:
            deleteany();
            break;
        default:
            printf("\t\tINVALID ENTRY");
            break;
        }
        printf("\t\tDo you want to continue(y/n) ");
        scanf("%s", & c);
    }
    while (c == 'y' || c == 'Y');
}
void insertfront() {
    newptr = (NODE * ) malloc(sizeof(NODE));
    printf("\t\tEnter the element: ");
    scanf("%d", & newptr -> data);
    newptr -> link = NULL;
    if (newptr == NULL)
        printf("\t\tInsufficient memmory");
    else {
        newptr -> link = header -> link;
        header -> link = newptr;
    }
}
void insertend() {
    newptr = (NODE * ) malloc(sizeof(NODE));
    if (newptr == NULL)
        printf("\t\tInsufficient memmory");
    else {
        printf("\t\tEnter the element: ");
        scanf("%d", & newptr -> data);
        newptr -> link = NULL;
        ptr = header;
        while (ptr -> link != NULL)
            ptr = ptr -> link;
        newptr -> link = ptr -> link;
        ptr -> link = newptr;
    }
}
void insertany() {
    int key;
    newptr = (NODE * ) malloc(sizeof(NODE));
    if (newptr == NULL)
        printf("\t\tInsufficient memmory");
    else {
        printf("\t\tenter the key");
        scanf("%d", & key);
        printf("\t\tenter the element");
        scanf("%d", & newptr -> data);
        ptr = header -> link;
        while (ptr -> data != key && ptr != NULL)
            ptr = ptr -> link;
        if (ptr == NULL)
            printf("\t\tkey is not found");
        else {
            newptr -> link = ptr -> link;
            ptr -> link = newptr;
        }
    }
}
void deletefront() {
    ptr = header -> link;
    ptr1 = ptr -> link;
    if (ptr == NULL)
        printf("\t\tEmpty list");
    else {
        header -> link = ptr1;
        printf("\t\tdeleted element is %d", ptr -> data);
        free(ptr);
    }
    printf("\n");
}
void deleteend() {
    ptr = header;
    ptr1 = ptr -> link;
    if (ptr1 == NULL)
        printf("\t\tEmpty list");
    else {
        while (ptr1 -> link != NULL) {
            ptr = ptr -> link;
            ptr1 = ptr1 -> link;
        }
        ptr -> link = NULL;
        printf("\t\tDeleted element is %d", ptr1 -> data);
        free(ptr1);
    }
    printf("\n");
}
void deleteany() {
    int key;
    ptr = header;
    ptr1 = ptr -> link;
    if (ptr1 == NULL)
        printf("\t\tEmpty list");
    else {
        printf("\t\tenter the key");
        scanf("%d", & key);
        while (ptr1 -> data != key && ptr1 != NULL) {
            ptr = ptr1;
            ptr1 = ptr1 -> link;
        }
        if (ptr1 == NULL)
            printf("\t\tKey not found");
        else if (ptr1 -> data == key) {
            ptr -> link = ptr1 -> link;
            printf("\t\tDeleted element is %d", ptr1 -> data);
            free(ptr1);
        }
        printf("\n");
    }
}
void traverse() {
    if (header -> link == NULL)
        printf("\t\tlist is empty\n");
    else {
        printf("\t\tElements are\n");
        ptr = header -> link;
        printf("\t\t");
        while (ptr != NULL) {
            printf(" %d", ptr -> data);
            ptr = ptr -> link;
        }
        printf("\n");
    }
}