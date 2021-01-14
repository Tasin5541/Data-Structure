#define SIZE 50
#include <ctype.h>
int stack[SIZE];
int top=-1;

void push(int elem);
int pop();

void main()
{
    char postfix[50],ch;
    int i=0,op1,op2;
    printf("Enter the Postfix Expression : ");
    gets(postfix);
    while( (ch=postfix[i++]) != '\0')
    {
        if(isdigit(ch)) push(ch-'0');
        else
        {
            op2=pop();
            op1=pop();
            switch(ch)
            {
            case '+':
                push(op1+op2);
                break;
            case '-':
                push(op1-op2);
                break;
            case '*':
                push(op1*op2);
                break;
            case '/':
                push(op1/op2);
                break;
            }
        }
    }
    printf("\nPostfix expression: %s\n",postfix);
    printf("\nResult after Evaluation: %d\n",stack[top]);
}

push(int elem)
{
    stack[++top]=elem;
}

int pop()
{
    return(stack[top--]);
}
