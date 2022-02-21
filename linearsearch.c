#include<stdio.h>

void main() {
    int a[50], i, n, elt, count;
    printf("\n\tLINEAR SEARCH");
    printf("\n\t________________\n\n");
    printf("\n\tEnter the limit:");
    scanf("%d", & n);
    printf("\n\tEnter the elements:");
    for (i = 0; i < n; i++) {
        scanf("%d", & a[i]);
    }
    printf("\n\tThe elements are:");
    for (i = 0; i < n; i++) {
        printf("\t%d", a[i]);
    }
    printf("\n\n\tEnter the element to be searched:");
    scanf("%d", & elt);
    count = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == elt) {
            count = count + 1;
        }
    }
    printf("\n\n\tThe element is present %d times", count);
}