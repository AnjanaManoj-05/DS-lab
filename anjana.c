#include <stdio.h>
#include <conio.h>
#include <string.h>
int index=0, pos=0, top = -1, length=0;
char symb, temp, infix[20], postfix[20], stack[20];

void infixtopostfix();
void push(char symb);
char pop();
int pred(char symb);
void main()
{
    //clrscr();
    printf("Enter the infix expression:");
    scanf("%s", &infix);
    infixtopostfix();
    printf("The infix expression is:%s\n", infix);
    printf("The postfix expression is:%s", postfix);
    }
void infixtopostfix()
{
    length = strlen(infix);
    push('#');
    while (index<length)
    {
        symb = infix[index];
        switch (symb)
        {
        case '(':
            push('(');
            break;

        case ')':
            temp = pop();
            while (temp != '(')
            {
                postfix[pos] = temp;
                pos++;
                temp = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (pred(stack[top]) >= pred(symb))
            {
                temp = pop();
                postfix[pos++] = temp;
            }
            push(symb);
            break;
        default:
            postfix[pos++] = symb;
        }
        index++;
    }
    while (top > 0)
    {
        temp = pop();
        postfix[pos++] = temp;
    }
}
void push(char symb)
{
    top += 1;
    stack[top] = symb;
}
char pop()
{
    char symb;
    symb = stack[top];
    top -= 1;
    return symb;
}
int pred(char symb)
{
    int p;
    switch (symb)
    {
    case '^':
        p = 3;
        break;
    case '*':
    case '/':
        p = 2;
        break;
    case '+':
    case '-':
        p = 1;
        break;
    case '(':
        p = 0;
        break;
    case '#':
        p = -1;
        break;
    }
    return p;
}

