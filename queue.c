#include <stdio.h>

void main() {
    int MAX_SIZE, CHOICE, REAR = -1, FRONT = -1, Q[50], ITEM, i;
    char CONT;
    printf("\n\tProgram to ENQUEUE, DEQUEUE or display an element from a QUEUE");
    printf("\n\t________________________________________________________________");
    printf("\n\tEnter the size of the QUEUE: ");
    scanf("%d", & MAX_SIZE);
    do {
        printf("\n\tMENU");
        printf("\n\n\t______\n");
        printf("\n\n\t1.ENQUEUE\n\n\t2.DEQUEUE\n\n\t3.Display\n\n\t4.Exit");
        printf("\n\n\n\tEnter your Choice  ");
        scanf("%d", & CHOICE);
        if (CHOICE == 1) {
            if (REAR == MAX_SIZE - 1) {
                printf("\n\nQueue is Full");
            } else {
                printf("\n\nEnter the number to be queued ");
                scanf("%d", & ITEM);
                if (REAR == -1 && FRONT == -1) {
                    FRONT = 0;
                }
                REAR = REAR + 1;
                Q[REAR] = ITEM;
            }
        } else if (CHOICE == 2) {
            if (FRONT == -1) {
                printf("\n\nQueue is Empty");
            } else {
                if (FRONT == REAR) {
                    FRONT = -1;
                    REAR = -1;
                } else {
                    FRONT = FRONT + 1;
                }
                printf("\n\n\nDEQUEUE Operation Succesfull");
            }
        } else if (CHOICE == 3) {
            if (FRONT == -1) {
                printf("\n\nQueue is Empty");
            } else {
                printf("\n\tThe Queue is:");
                for (i = FRONT; i <= REAR; i++) {
                    printf("\t\t%d", Q[i]);
                }
            }
        } else {
            printf("\n\nInvalid Input!!!!!!!!!!!!!!");
        }
        printf("\n\n\nDo you wany to continue? (Y/N)");
        scanf("%s", & CONT);
    } while (CONT == 'Y' || CONT == 'y');
}
