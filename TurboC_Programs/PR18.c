/* Program 18: Sorted Singly Linked List - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct list
{
    int info;
    struct list *next;
};

struct list *start;

void sorted();
void display(struct list *);

void main()
{
    int choice;
    clrscr();
    start = NULL;

menu:
    /* Step 1: Show menu.
       Why: Each insertion automatically keeps the list sorted. */
    printf("\n1. Insert item in sorted order");
    printf("\n2. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            sorted();
            display(start);
            goto menu;
        case 2:
            exit(0);
        default:
            printf("\nWrong choice.");
            goto menu;
    }
}

void sorted()
{
    struct list *new1, *save, *ptr;
    int item;

    /* Step 2: Allocate and fill a new node. */
    new1 = (struct list *)malloc(sizeof(struct list));
    if(new1 == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }

    printf("Enter an item: ");
    scanf("%d", &item);
    new1->info = item;

    /* Step 3: Empty list means new node becomes first node. */
    if(start == NULL)
    {
        new1->next = NULL;
        start = new1;
        return;
    }

    /* Step 4: If item is smaller than first node, insert at beginning. */
    if(item < start->info)
    {
        new1->next = start;
        start = new1;
        return;
    }

    /* Step 5: Find the first node greater than the new item. */
    save = start;
    ptr = start->next;

    while(ptr != NULL)
    {
        if(item < ptr->info)
        {
            new1->next = ptr;
            save->next = new1;
            return;
        }

        save = ptr;
        ptr = ptr->next;
    }

    /* Step 6: No greater item was found, so append at end. */
    new1->next = NULL;
    save->next = new1;
}

void display(struct list *p)
{
    /* Step 7: Traverse the already-sorted list from start to NULL. */
    printf("\nSorted linked list: ");
    while(p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
}
