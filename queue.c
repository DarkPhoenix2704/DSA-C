#include<stdio.h>

void main() {
    int no, i, front = -1, rear = -1, k, queue[50], element, n;
    char c;
    printf("\n\n\n\tPROGRAM TO INSERT, DELETE AND DISPLAY ELEMENTS TO QUEUE");
    printf("\n\t.......................................................\n\n\n");
    printf("\n\n\tEnter the size of the queue: ");
    scanf("%d", & n);
    do {
        printf("\n\n\n\t\t\t\tMENU\n\n");
        printf("\t\t1.INSERT\n\n\t\t2.DELETE\n\n\t\t3.DISPLAY\n\n\t\t4.EXIT\n\n\t\tEnter your choice: ");
        scanf("%d", & no);
        if (no == 1) {
            if (rear == (n - 1))
                printf("\n\t\tOverflow");
            else {
                printf("\n\n\t\tEnter the element: ");
                scanf("%d", & element);
                if (front == -1 && rear == -1)
                    front = 0;
                rear++;
                queue[rear] = element;
            }
        }
        if (no == 2) {
            if (front == -1)
                printf("\n\t\tUnderflow\n");
            else {
                k = queue[front];
                printf("\n\t\tDeleted element is %d ", k);
            }
            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
        if (no == 3) {
            if (front == -1 && rear == -1)
                printf("\n\t\tUnderflow\n");
            else {
                printf("\n\t\tQueue elements are\n ");
                for (i = front; i <= rear; i++) {
                    printf("\n\n\t\t%d", queue[i]);
                }
            }
        }
        if (no == 4)
            break;
        printf("\n\n\t\tDo you want to continue(y/n) ");
        scanf(" %s", & c);
    }
    while (c == 'y' || c == 'Y');
}