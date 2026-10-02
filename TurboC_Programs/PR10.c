/* Program 10: Stack Operations - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5

/* MAX+1 is used because this program keeps stack positions from 1 to MAX. */
int stack[MAX + 1];
int top = 0;

void push();
void pop();
void peep();
void change();
void disp();

void main()
{
    int choice;
    clrscr();

menu:
    /* Step 1: Show stack operation menu. */
    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Peep");
    printf("\n4. Change");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            push();
            disp();
            goto menu;
        case 2:
            pop();
            disp();
            goto menu;
        case 3:
            peep();
            disp();
            goto menu;
        case 4:
            change();
            disp();
            goto menu;
        case 5:
            exit(0);
        default:
            printf("\nWrong choice.");
            goto menu;
    }
}

void push()
{
    int value;

    /* Step 2: Check overflow before insertion.
       Why: top cannot move beyond MAX. */
    if(top >= MAX)
    {
        printf("\nStack overflow.\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    /* Step 3: Move top up and store the new value. */
    top++;
    stack[top] = value;
}

void pop()
{
    int value;

    /* Step 4: Check underflow before deletion. */
    if(top == 0)
    {
        printf("\nStack underflow.\n");
        return;
    }

    value = stack[top];
    stack[top] = 0;
    top--;
    printf("\n%d is deleted.\n", value);
}

void peep()
{
    int pos, index;

    /* Step 5: Read position from top.
       Why: Peep checks an element without removing it. */
    printf("Enter position from top: ");
    scanf("%d", &pos);

    if(pos <= 0 || pos > top)
    {
        printf("Invalid position or stack underflow.\n");
        return;
    }

    index = top - pos + 1;
    printf("Element at position %d from top is %d\n", pos, stack[index]);
}

void change()
{
    int pos, value, index;

    /* Step 6: Read position and replacement value. */
    printf("Enter position from top to change: ");
    scanf("%d", &pos);

    if(pos <= 0 || pos > top)
    {
        printf("Invalid position or stack underflow.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    index = top - pos + 1;
    stack[index] = value;
}

void disp()
{
    int i;

    /* Step 7: Display only active stack elements. */
    if(top == 0)
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nStack contains: ");
    for(i = top; i >= 1; i--)
        printf("%d ", stack[i]);
    printf("\n");
}
