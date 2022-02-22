#include<stdio.h>

#include<string.h>

void push(char);
void push1(int);
int priority(char);
void read();
int top = -1, top1 = -1, j = 0, i, x, y;
char stk[50], stk1[50], a[50], ch, post[50];
void main() {
    printf("\nProgram for Infix to Postfix Evaluation");
    printf("\n_______________________________________");
    printf("\nEnter the expression ");
    gets(a);
    for (i = 0; a[i] != '\0'; i++) {
        ch = a[i];
        switch (ch) {
        case '(':
            push(ch);
            break;
        case ')':
            while (stk[top] != '(') {
                post[j++] = stk[top];
                top--;
            }
            top--;
            break;
        case '+':
        case '-':
        case '^':
        case '/':
        case '*':
            if (top == -1 || stk[top] == '(') {
                push(ch);
            } else {
                x = priority(ch);
                y = priority(stk[top]);
                if (y >= x) {
                    post[j++] = stk[top];
                    top--;
                    push(ch);
                } else {
                    push(ch);
                }
            }
            break;
        default:
            if (isalpha(ch)) {
                post[j++] = ch;
            }
            break;
        }
    }
    while (stk[top] != '\0') {
        post[j++] = stk[top];
        top--;
    }
    post[j] = '\0';
    printf("\nPostfix expresiion is \t");
    puts(post);
    read();
}
void push(char ch) {
    top++;
    stk[top] = ch;
}
void push1(int ch) {
    top1++;
    stk1[top1] = ch;
}
int priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return 0;
    }
}
void read() {
    int c, o1, o2;
    for (i = 0; post[i] != '\0'; i++) {
        ch = post[i];
        if (isalpha(ch)) {
            printf("\nEnter the value for %c ", ch);
            scanf("%d", & c);
            push1(c);
        } else {
            o1 = stk1[top1];
            top1--;
            o2 = stk1[top1];
            top1--;
            switch (ch) {
            case '+':
                x = o1 + o2;
                break;
            case '-':
                x = o1 - o2;
                break;
            case '*':
                x = o1 * o2;
                break;
            case '/':
                x = o1 / o2;
                break;
            case '^':
                x = o1 ^ o2;
                break;
            default:
                break;
            }
            push1(x);
        }
    }
    printf("\nValue of Expresiion is %d ", stk1[top1]);
}
