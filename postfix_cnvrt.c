#define SIZE 50
#include <ctype.h>
char stack[SIZE];
int top=-1;

void push(char elem);
char pop();
int precedence(char elem);

void main()
{
    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;
    printf("Enter the Infix Expression : ");
    gets(infix);
    push('#');
    while( (ch=infix[i++]) != '\0')
    {
        if( ch == '(') push(ch);
        else
            if(isalnum(ch)) postfix[k++]=ch;
            else
                if( ch == ')')
                {
                    while( stack[top] != '(')
                        postfix[k++]=pop();
                    elem=pop();
                }
                else
                {
                    while( precedence(stack[top]) >= precedence(ch) )
                        postfix[k++]=pop();
                    push(ch);
                }
    }
    while( stack[top] != '#')
        postfix[k++]=pop();
    postfix[k]='\0';
    printf("\n\nInfix Expression: %s\nPostfix Expression: %s\n",infix,postfix);
}

void push(char elem)
{
    stack[++top]=elem;
}

char pop()
{
    return(stack[top--]);
}

int precedence(char elem)
{
    switch(elem)
    {
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}
