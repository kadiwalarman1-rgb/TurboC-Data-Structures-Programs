/* Program 14: Double Ended Queue (Deque) - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5

/* Positions 1 to MAX are used, therefore size is MAX+1. */
int d_queue[MAX + 1];
int rear = 0;
int front = 0;

void r_insert();
void r_delet();
void l_insert();
void l_delet();
void disp();

void main()
{
    int choice;
    clrscr();

menu:
    /* Step 1: Show deque operation menu. */
    printf("\n1. Right Insert");
    printf("\n2. Right Delete");
    printf("\n3. Left Insert");
    printf("\n4. Left Delete");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            r_insert();
            disp();
            goto menu;
        case 2:
            r_delet();
            disp();
            goto menu;
        case 3:
            l_insert();
            disp();
            goto menu;
        case 4:
            l_delet();
            disp();
            goto menu;
        case 5:
            exit(0);
        default:
            printf("\nWrong choice.");
            goto menu;
    }
}

void r_insert()
{
    int value;

    /* Step 2: Right insertion needs free space after rear. */
    if(rear >= MAX)
    {
        printf("\nDeque overflow at right side.\n");
        return;
    }

    printf("Enter value to insert at right: ");
    scanf("%d", &value);

    rear++;
    d_queue[rear] = value;

    if(front == 0)
        front = 1;
}

void l_insert()
{
    int value;

    /* Step 3: Left insertion needs free position before front. */
    if(front == 1)
    {
        printf("\nDeque overflow at left side.\n");
        return;
    }

    printf("Enter value to insert at left: ");
    scanf("%d", &value);

    /* Step 4: If empty, start from last slot so left insertion is valid. */
    if(front == 0)
    {
        front = MAX;
        rear = MAX;
    }
    else
        front--;

    d_queue[front] = value;
}

void l_delet()
{
    int value;

    /* Step 5: Empty deque cannot delete. */
    if(front == 0)
    {
        printf("\nDeque is empty.\n");
        return;
    }

    value = d_queue[front];
    d_queue[front] = 0;
    printf("\n%d deleted from left.\n", value);

    if(front == rear)
    {
        front = 0;
        rear = 0;
    }
    else
        front++;
}

void r_delet()
{
    int value;

    /* Step 6: Delete the element at rear. */
    if(front == 0)
    {
        printf("\nDeque is empty.\n");
        return;
    }

    value = d_queue[rear];
    d_queue[rear] = 0;
    printf("\n%d deleted from right.\n", value);

    if(front == rear)
    {
        front = 0;
        rear = 0;
    }
    else
        rear--;
}

void disp()
{
    int i;

    /* Step 7: Display the logical deque from front to rear. */
    if(front == 0)
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque contains: ");
    for(i = front; i <= rear; i++)
        printf("%d ", d_queue[i]);
    printf("\n");
}
