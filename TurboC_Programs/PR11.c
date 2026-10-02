/* Program 11: Infix to Postfix Conversion - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

#define MAX 50

int priority(char);
void push(char);
char pop();

int top = -1;
char infix[MAX], postfix[MAX], stack[MAX];

void main()
{
    int i, j;
    char ch;
    clrscr();

    /* Step 1: Read infix expression without spaces.
       Why: The converter scans one symbol at a time. */
    printf("Enter infix expression: ");
    scanf("%s", infix);

    j = 0;

    /* Step 2: Scan the expression from left to right. */
    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        /* Step 3: Operands go directly to postfix. */
        if(isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        /* Step 4: Opening bracket is pushed to stack. */
        else if(ch == '(')
        {
            push(ch);
        }
        /* Step 5: Closing bracket pops until matching '('. */
        else if(ch == ')')
        {
            while(top >= 0 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }

            if(top >= 0 && stack[top] == '(')
                pop();
            else
            {
                printf("Invalid expression: unmatched parenthesis.");
                getch();
                return;
            }
        }
        /* Step 6: Handle operators according to precedence.
           Why: Higher-precedence operators must appear earlier in postfix. */
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$')
        {
            while(top >= 0 && stack[top] != '(' &&
                 (priority(stack[top]) > priority(ch) ||
                 (priority(stack[top]) == priority(ch) && ch != '$')))
            {
                postfix[j] = pop();
                j++;
            }
            push(ch);
        }
        else
        {
            printf("Invalid symbol in expression.");
            getch();
            return;
        }
    }

    /* Step 7: Pop remaining operators from stack. */
    while(top >= 0)
    {
        if(stack[top] == '(')
        {
            printf("Invalid expression: unmatched parenthesis.");
            getch();
            return;
        }
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    /* Step 8: Display converted postfix expression. */
    printf("Converted postfix expression: %s", postfix);
    getch();
}

void push(char ch)
{
    if(top < MAX - 1)
    {
        top++;
        stack[top] = ch;
    }
}

char pop()
{
    char ch;
    ch = stack[top];
    top--;
    return ch;
}

int priority(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '$')
        return 3;
    else
        return 0;
}
