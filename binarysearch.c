#include<stdio.h>

void main() {
    int arr[50], num, size, i, temp, end, mid, j, beg = 0;
    printf("Enter the size of the array:- ");
    scanf("%d", & size);
    printf("Enter the elements of the array\n");
    for (i = 0; i < size; i++) {
        scanf("%d", & arr[i]);
    }
    printf("\n\nSorting array......");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n\nEnter the element to be searched:- ");
    scanf("%d", & num);
    end = size - 1;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if (num < arr[mid]) {
            end = mid - 1;
        } else if (num > arr[mid]) {
            beg = mid + 1;
        } else if (num == arr[mid]) {
            printf("\n\nElement Found !!!!!!!!!");
            break;
        }
    }
    if (beg > end) {
        printf("\n\nElement not Found!!!!!!!");
    }
}
