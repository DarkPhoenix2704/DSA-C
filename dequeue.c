#include<stdio.h>
void main() {
    int arr[50], maxSize, choice, option, front = -1, rear = -1, item;
    printf("Enter the size of DEQUEUE: ");
    scanf("%d", &maxSize);
    do {
        printf("1.Insert Front\n2.Insert RearEnd\n3.Delete Front\n4.Delete Rear\n5.Display ");
        printf("\nEnter the opton: ");
        scanf("%d", &option);
        if (option == 1) {
            if (front == 0) {
                printf("\nQueue Overflow");
            } else {
                printf("\nEnter the element to be Inserted: ");
                scanf("%d", &item);
                if (front == -1)
                {
                    front = 0;
                    rear = 0;
                    arr[front] = item;
                }
                front--;
                arr[front] = item;
            }
        } else if(option == 2) {
            if (rear == maxSize - 1)
            {
                printf("\nQueue overflow");
            } else {
                if (front == -1)
                {
                    front = 0;
                }
                printf("\nEnter the element to be Inserted: ");
                scanf("%d", &item);
                rear++;
                arr[rear] = item;
            }
        } else if (option == 3) {
            if (front == -1)
            {
                printf("\nQueue is Empty");
            } else if( front == rear) {
                item = arr[front];
                front = -1;
                rear = -1;
                printf("\n %d id removed", item);
            } else {
                item = arr[front];
                front++;
                printf("\n %d id removed", item);

            }
        } else if (option == 4) {
            if (rear == -1)
            {
                printf("\n Queue underflow");
            } else if( rear == front ) {
                item = arr[rear];
                rear = -1;
                front = -1;
                printf("\n %d id removed", item);
            } else {
                item = arr[rear];
                rear--;
                printf("\n %d id removed", item);
            }
        } else if (option == 5) {
            if (front == -1) {
                printf("\nQueue is Empty");
            } else {
                printf("\nThe elements are  ");
                for (int i = front; i <= rear; i++) {
                    printf("\t%d", arr[i]);
                }  
            }
        } else {
            printf("\nInvalid Option");
        }
        printf("\nDo you want to continue? (Yes - 1 / No - 0): ");
        scanf("%d", &choice);
    } while (choice == 1);
    
}