#include<stdio.h>
void main() {
    int arr[50], maxSize, choice, operation, item, top=-1;
    printf("Enter the maxSize of Stack: ");
    scanf("%d",&maxSize);
    do {
    printf("1.Push\n2.Pop\n3.Display");
    printf("\nEnter the Operation: ");
    scanf("%d", &operation);
    switch (operation)
    {
    case 1:
        if(top == maxSize - 1){
            printf("Stack Overflow");
        } else {
            printf("Enter the element to be added: ");
            scanf("%d",&item);
            top++;
            arr[top] = item;
        }
        break;
    case 2:
        if(top == -1) {
            printf("Stack Underflow");
        } else {
            item = arr[top];
            top--;
            printf("%d is removed", item);
        }
        break;
    case 3:
        if (top == -1)
        {
            printf("\nStack underflow");
        } else {
            printf("The elements are ");
            for (int i = top; i > -1; i--)
            {
                printf("%d\t", arr[i]);
            }
            
        }
        break;
    default:
    printf("\nInvalid Option");
        break;
    }
    printf("\nDo you want to continue(Yes - 1 / No - 0)  :");
    scanf("%d", &choice);
    } while(choice == 1);
}