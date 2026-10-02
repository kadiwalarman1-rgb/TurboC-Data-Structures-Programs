/* Program 12: Postfix Expression Evaluation - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int);
int pop();

void main()
{
    char postfix[MAX];
    int a, b, c, x, i;
    clrscr();

    /* Step 1: Read postfix expression without spaces.
       Why: This version evaluates single-digit operands like 23+ or 82/. */
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    /* Step 2: Scan every symbol in postfix expression. */
    for(i = 0; postfix[i] != '\0'; i++)
    {
        /* Step 3: If symbol is a digit, convert it to integer and push. */
        if(isdigit(postfix[i]))
        {
            x = postfix[i] - '0';
            push(x);
        }
        else
        {
            /* Step 4: An operator needs two operands on the stack. */
            if(top < 1)
            {
                printf("Invalid postfix expression.");
                getch();
                return;
            }

            a = pop();
            b = pop();

            /* Step 5: Apply operator in correct order b operator a. */
            if(postfix[i] == '+')
                c = b + a;
            else if(postfix[i] == '-')
                c = b - a;
            else if(postfix[i] == '*')
                c = b * a;
            else if(postfix[i] == '/')
            {
                if(a == 0)
                {
                    printf("Division by zero is not allowed.");
                    getch();
                    return;
                }
                c = b / a;
            }
            else if(postfix[i] == '$')
                c = (int)pow(b, a);
            else
            {
                printf("Invalid operator in postfix expression.");
                getch();
                return;
            }

            /* Step 6: Push result back so it can be used by later operators. */
            push(c);
        }
    }

    /* Step 7: Exactly one value must remain after correct evaluation. */
    if(top != 0)
        printf("Invalid postfix expression.");
    else
        printf("Answer: %d", stack[top]);

    getch();
}

void push(int x)
{
    if(top < MAX - 1)
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    int x;
    x = stack[top];
    top--;
    return x;
}
