#include<stdio.h>
void main() {
    int arr[50], maxSize, front=-1, rear=-1, choice, option, item;
    printf("Enter size of Queue: ");
    scanf("%d", &maxSize);
    do
    {
        printf("\n1.Rear Addition \n2.Front Deletion \n3.Display");
        printf("\nEnter the Option: ");
        scanf("%d", &option);
        if (option == 1)
        {
            if(rear == maxSize - 1) {
                printf("\nQueue is Full");
            } else {
                if (rear == -1 && front == -1) {
                    front = 0;
                }
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                rear++;
                arr[rear] = item;
            }
        } else if (option == 2) {
            if (front == -1) {
                printf("\nQueue is Empty");
            } else if (front == rear) {
                item = arr[front];
                front = -1;
                rear = -1;
                printf("\n%d is removed",item);
            } else {
                item = arr[front];
                front++;
                printf("\n%d is removed",item);
            }
        } else if (option == 3) {
            if (front == -1)
            {
                printf("\nQueue is Empty");
            } else {
                printf("\nThe elements are  ");
                for (int i = front; i < rear+1; i++)
                {
                    printf("%d\t", arr[i]);
                }
            }
        } else {
            printf("\nInvalid Input");
        }
        
        printf("\nDo you want to continue(Yes - 1 / No - 0): ");
        scanf("%d", &choice);
        
    } while (choice == 1);
    
    
}