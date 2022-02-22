#include<stdio.h>

void main() {
    int arr[50], i, num, size, flag = -1;
    printf("Enter the size of the array:- ");
    scanf("%d", & size);
    printf("Enter the elements of the array\n");
    for (i = 0; i < size; i++) {
        scanf("%d", & arr[i]);
    }
    printf("\n\nEnter the element to be searched:- ");
    scanf("%d", & num);
    for (i = 0; i < size; i++) {
        if (num == arr[i]) {
            flag = 0;
            break;
        }
    }
    if (flag == -1) {
        printf("\nElement is not found!!!!");
    } else {
        printf("Element is found at %d", i + 1);
    }
}
