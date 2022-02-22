#include <stdio.h>

void main() {
    int MAX_SIZE, CHOICE, REAR = -1, FRONT = -1, Q[50], ITEM, i;
    char CONT;
    printf("\nProgram to Insert, Delete or Display an elements from a Circular QUEUE");
    printf("\n________________________________________________________________");
    printf("\nEnter the size of the Circular QUEUE: ");
    scanf("%d", & MAX_SIZE);
    do {
        printf("\nMENU");
        printf("\n____");
        printf("\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit");
        printf("\n\n\nEnter your Choice  ");
        scanf("%d", & CHOICE);
        if (CHOICE == 1) {
            printf("\n\nEnter the element to inserted ");
            scanf("%d", & ITEM);
            if (FRONT == (REAR + 1) % MAX_SIZE) {
                printf("\n\nCircular Queue is Full");
            } else if (FRONT == -1) {
                FRONT = 0;
                REAR = 0;
                Q[REAR] = ITEM;
                printf("\n\nValue is inserted");
            } else {
                REAR = (REAR + 1) % MAX_SIZE;
                Q[REAR] = ITEM;
                printf("\n\nValue is inserted");
            }
        } else if (CHOICE == 2) {
            if (FRONT == -1) {
                printf("\n\nCircular Queue is Empty");
            } else if (FRONT == REAR) {
                FRONT = -1;
                REAR = -1;
                printf("\n\nElement is deleted");
            } else {
                FRONT = (FRONT + 1) % MAX_SIZE;
                printf("\n\nElement is deleted");
            }
        } else if (CHOICE == 3) {
            if (FRONT == -1) {
                printf("\n\nCircular Queue is Empty");
            } else {
                printf("\n\nCircular Queue is\n");
                for (i = FRONT; i <= REAR; i++) {
                    printf("\t%d", Q[i]);
                }
            }

        } else {
            printf("\n\nInvalid Input!!!!!!!!!!!!!!");
        }
        printf("\n\n\nDo you wany to continue? (Y/N) ");
        getchar();
        scanf("%c", & CONT);
    } while (CONT == 'Y' || CONT == 'y');
}
