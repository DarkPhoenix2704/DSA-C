#include <stdio.h>

void main() {
    int MAX_SIZE, CHOICE, REAR = -1, FRONT = -1, Q[50], ITEM, i;
    char CONT;
    printf("\nProgram to ENQUEUE, DEQUEUE or display an element from a QUEUE");
    printf("\n______________________________________________________________");
    printf("\nEnter the size of the QUEUE: ");
    scanf("%d", & MAX_SIZE);
    do {
        printf("\nMENU");
        printf("\n____");
        printf("\n1.ENQUEUE at REAR end\n2.ENQUEUE at FRONTEND\n3.DEQUEUE from Front End\n4.DEQUEUE From Rear END \n5.Display\n6.Exit");
        printf("\n\nEnter your Choice  ");
        scanf("%d", & CHOICE);
        if (CHOICE == 1) {
            if (REAR == MAX_SIZE - 1) {
                printf("\nQueue is Full");
            } else {
                printf("\nEnter the number to be queued ");
                scanf("%d", & ITEM);
                if (FRONT == -1) {
                    FRONT = 0;
                    REAR = 0;
                } else {
                    REAR = REAR + 1;
                }
                Q[REAR] = ITEM;
            }
        } else if (CHOICE == 2) {
            if (FRONT == 0) {
                printf("\nQueue is Full");
            } else {
                printf("\nEnter the number to be queued ");
                scanf("%d", & ITEM);
                if (FRONT == -1) {
                    FRONT = 0;
                    REAR = 0;
                    Q[FRONT] = ITEM;
                } else {
                    FRONT = FRONT - 1;
                    Q[FRONT] = ITEM;
                }
            }
        } else if (CHOICE == 3) {
            if (FRONT == -1) {
                printf("\nQueue is Empty");
            } else {
                if (FRONT == REAR) {
                    FRONT = -1;
                    REAR = -1;
                } else {
                    FRONT = FRONT + 1;
                }
                printf("\nDEQUEUE Operation Succesfull");
            }
        } else if (CHOICE == 4) {
            if (REAR == -1) {
                printf("\nQueue is Empty");
            } else {
                if (FRONT == REAR) {
                    FRONT = REAR - 1;
                } else {
                    REAR--;
                }

            }
        } else if (CHOICE == 5) {
            if (FRONT == -1 && REAR == -1) {
                printf("\nQueue is Empty");
            } else {
                printf("\nThe Queue is:");
                for (i = FRONT; i <= REAR; i++) {
                    printf("\t%d", Q[i]);
                }
            }
        } else {
            printf("\nInvalid Input!!!!!!!!!!!!!!");
        }
        printf("\nDo you wany to continue? (Y/N)");
        scanf("%s", & CONT);
    } while (CONT == 'Y' || CONT == 'y');
}
