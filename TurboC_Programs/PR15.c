/* Program 15: Circular Queue Operations - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5

/* Positions 1 to MAX are used. */
int c_queue[MAX + 1];
int rear = 0;
int front = 0;

void insert();
void delet();
void disp();

void main()
{
    int choice;
    clrscr();

menu:
    /* Step 1: Show circular queue menu. */
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            insert();
            disp();
            goto menu;
        case 2:
            delet();
            disp();
            goto menu;
        case 3:
            exit(0);
        default:
            printf("\nWrong choice.");
            goto menu;
    }
}

void insert()
{
    int value;

    /* Step 2: Check circular overflow condition.
       Why: Queue is full when front is immediately after rear. */
    if((front == 1 && rear == MAX) || (front == rear + 1))
    {
        printf("\nCircular queue overflow.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    /* Step 3: Move rear to correct circular position. */
    if(front == 0)
    {
        front = 1;
        rear = 1;
    }
    else if(rear == MAX)
        rear = 1;
    else
        rear++;

    c_queue[rear] = value;
}

void delet()
{
    int value;

    /* Step 4: Check underflow before deletion. */
    if(front == 0)
    {
        printf("\nCircular queue underflow.\n");
        return;
    }

    value = c_queue[front];
    c_queue[front] = 0;
    printf("\n%d is deleted.\n", value);

    /* Step 5: Update front in circular form. */
    if(front == rear)
    {
        front = 0;
        rear = 0;
    }
    else if(front == MAX)
        front = 1;
    else
        front++;
}

void disp()
{
    int i;

    /* Step 6: Traverse from front to rear with wrap-around. */
    if(front == 0)
    {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular queue contains: ");
    i = front;
    while(1)
    {
        printf("%d ", c_queue[i]);
        if(i == rear)
            break;
        if(i == MAX)
            i = 1;
        else
            i++;
    }
    printf("\n");
}
