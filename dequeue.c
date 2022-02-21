#include<stdio.h>

void main() {
    int no, i, front = -1, rear = -1, k, queue[50], element, n;
    char c;
    printf("\n\tPROGRAM TO INSERT, DELETE AND DISPLAY ELEMENTS TO DEQUEUE\n");
    printf("\t.......................................................");
    printf("\n\tEnter the size of the queue: ");
    scanf("%d", & n);
    do {
        printf("\t\t\t\tMENU\n");
        printf("\t\t1.INSERT_FRONT\n\t\t2.INSERT_END\n\t\t3.DELETE_FRONT\n\t\t4.DELETE_END\n\t\t5.DISPLAY\n\t\t6.EXIT\n\t\tEnter your choice: ");
        scanf("%d", & no);
        if (no == 1) {
            if (front == 0)
                printf("\t\tOverflow\n");
            else {
                printf("\t\tEnter the element: ");
                scanf("%d", & element);
                if (front == -1) {
                    front = 0;
                    rear = 0;
                    queue[front] = element;
                } else if (front != 0) {
                    front = front - 1;
                    queue[front] = element;
                }
            }
        }
        if (no == 2) {
            if (rear == n - 1)
                printf("\t\tOverflow\n");
            else {
                printf("\t\tEnter the element: ");
                scanf("%d", & element);
                if (front == -1) {
                    front = rear = 0;
                    queue[rear] = element;
                } else {
                    rear = rear + 1;
                    queue[rear] = element;
                }
            }
        }
        if (no == 3) {
            if (front == -1)
                printf("\t\tUnderflow\n");
            else {
                k = queue[front];
                printf("\t\tDeleted element is %d ", k);
                printf("\n");
                if (front == rear)
                    front = rear = -1;
                else
                    front++;
            }
        }
        if (no == 4) {
            if (rear == -1)
                printf("\t\tUnderflow\n");
            else {
                k = queue[rear];
                printf("\t\tDeleted element is %d ", k);
                printf("\n");
                if (front == rear)
                    front = rear = -1;
                else
                    rear--;
            }
        }
        if (no == 5) {
            if (front == -1 && rear == -1)
                printf("\t\tUnderflow\n");
            else {
                printf("\t\tQueue elements are ");
                for (i = front; i <= rear; i++)
                    printf("%d ", queue[i]);
                printf("\n");
            }
        }
        if (no == 6)
            break;
        printf("\t\tDo you want to continue(y/n) ");
        scanf(" %s", & c);
    }
    while (c == 'y' || c == 'Y');
}