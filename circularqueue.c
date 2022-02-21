#include<stdio.h>

void main() {
    int no, i, front = 0, rear = 0, k, queue[50], element, size, next = 1;
    char c;
    printf("\n\tPROGRAM TO INSERT, DELETE AND DISPLAY ELEMENTS TO CIRCULARQUEUE");
    printf("\n\t.......................................................");
    printf("\n\tEnter the size of the queue: ");
    scanf("%d", & size);
    do {
        printf("\n\t\t\t\tMENU\n\n");
        printf("\t\t1.INSERT\n\t\t2.DELETE\n\t\t3.DISPLAY\n\t\t4.EXIT\n\t\tEnter your choice: ");
        scanf("%d", & no);
        if (no == 1) {
            if (rear == size - 1) {
                printf("\n overflow ");
            }
            printf("\t\tEnter the element: ");
            scanf("%d", & element);
            if (front == 0 && rear == 0) {
                front = rear = 1;
                queue[rear] = element;
            } else {
                next = (rear % size) + 1;
                if (next == front)
                    printf("\t\tOverflow\n");
                else {
                    rear = next;
                    queue[rear] = element;
                }
            }
        }
        if (no == 2) {
            if (front == 0)
                printf("\t\tUnderflow\n");
            else {
                k = queue[front];
                printf("\t\tDeleted element is %d\n", k);
            }
            if (front == rear)
                front = rear = 0;
            else
                front = (front % size) + 1;
        }
        if (no == 3) {
            if (front == 0 && rear == 0)
                printf("\t\tUnderflow\n");
            else {
                printf("\t\tQueue elements are");
                if (front < rear) {
                    for (i = front; i <= rear; i++)
                        printf("\n\t%d\t", queue[i]);
                } else {
                    for (i = front; i <= size; i++)
                        printf("\n\t\t%d", queue[i]);
                    for (i = 1; i <= rear; i++)
                        printf("\n\t\t%d", queue[i]);
                }
            }
        }
        if (no == 4)
            break;
        printf("\t\tDo you want to continue(y/n):");
        scanf("%s", & c);
    }
    while (c == 'y' || c == 'Y');
}