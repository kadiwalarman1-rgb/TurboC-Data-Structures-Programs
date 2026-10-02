/* Program 13: Linear Queue Operations - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5

/* MAX+1 is required because queue positions are 1 to MAX. */
int queue[MAX + 1];
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
    /* Step 1: Show queue operation menu. */
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

    /* Step 2: Check whether rear reached MAX.
       Why: A linear queue cannot insert beyond the last array position. */
    if(rear >= MAX)
    {
        printf("\nQueue overflow.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    /* Step 3: Move rear and store the new value. */
    rear++;
    queue[rear] = value;

    /* Step 4: First insertion also initializes front. */
    if(front == 0)
        front = 1;
}

void delet()
{
    int value;

    /* Step 5: front==0 means queue is empty. */
    if(front == 0)
    {
        printf("\nQueue underflow.\n");
        return;
    }

    value = queue[front];
    queue[front] = 0;
    printf("\n%d is deleted.\n", value);

    /* Step 6: Reset both pointers after deleting last element. */
    if(front == rear)
    {
        front = 0;
        rear = 0;
    }
    else
        front++;
}

void disp()
{
    int i;

    /* Step 7: Display active queue elements from front to rear. */
    if(front == 0)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contains: ");
    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
