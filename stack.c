#include<stdio.h>

void main() {
    int st[50], top = -1, k, n, i, si;
    char ch;
    printf("\n\tProgram to push ,pop or display an element from a stack");
    printf("\n\t_____________________________________________________________\n\n");
    printf("\n\tEnter the size of the stack:");
    scanf("%d", & si);
    do {
      printf("\n\t\tMENU");
      printf("\n\t\t_____\n");
      printf("\n\n\t1.Push\n\n\t2.Pop\n\n\t3.Display\n\n\t4.Exit");
      printf("\n\n\tEnter your choice:");
      scanf("%d", & n);
      if (n == 1) {
        if (top == si - 1) {
          printf("\n\tStack is overflow");
          else {
            printf("\n\tEnter the element to be inserted:");
            scanf("%d", & k);
            top++;
            st[top] = k;
            printf("\n\tThe entered element is %d", st[top]);
          }
        } else if (n == 2) {
          if (top == -1) {
            printf("\n\tStack is underflow");
          } else {
            printf("\n\tThe deleted element is %d", st[top]);
            top--;
          }
        } else if (n == 3) {
          if (top == -1) {
            printf("\n\tStack underflow");
          } else {
            printf("\n\tThe stack is:");
            for (i = top; i >= 0; i--) {
              printf("\t\t%d", st[i]);
            }
          }
        } else {
          break;
        }
        printf("\n\n\tDo you want to continue (Y/N) ?");
        scanf(" %s", & ch);
      }
      while ((ch == 'Y') || (ch == 'y'));
      getch();
    }
}