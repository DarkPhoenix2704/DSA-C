#include<stdio.h>
void main() {
    int queue[50], maxSize, choice, option, item, front = -1, rear = -1;
    printf("Enter the size of Circular Queue: ");
    scanf("%d", &maxSize);
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        if (option == 1) {
            if (front == ((rear + 1) % maxSize)) {
                printf("\nQueue is filled");
            } else {
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                if (front == -1 && rear == -1) {
                    front = 0;
                    rear = 0;
                } else {
                    rear = (rear + 1) % maxSize;
                }
                queue[rear] = item; 
            }
        } else if(option == 2) {
            if (front == -1) {
                printf("\nQueue is empty");
            } else {
                if (front == rear) {
                    item = queue[front];
                    front = rear = -1;
                } else {
                    item = queue[front];
                    front = (front + 1) % maxSize;
                }
                printf("\n%d is removed",item);
            }
        } else if(option == 3) {
            if (front == 0 && rear == 0) {
                printf("\nUnderflow");
            } else {
                if (front < rear) {
                    printf("\nThe Elemets are    ");
                    for (int i = front; i <= rear; i++) {
                        printf("\t%d", queue[i]);
                    }
                } else {
                    printf("\nThe Elemets are    ");
                    for (int i = front; i <= maxSize; i++) {
                        printf("\t%d", queue[i]);
                    }
                    for (int i = 0; i <= rear; i++) {
                        printf("\t%d", queue[i]);
                    }
                    
                }
            }
        }   
        printf("\nDo you want to continue? (Yes - 1 / No - 0)");
        scanf("%d", &choice);
    } while (choice == 1);
    
}