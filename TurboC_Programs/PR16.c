/* Program 16: Singly Linked List Operations - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct linklist
{
    int info;
    struct linklist *next;
};

struct linklist *start;

void create(struct linklist *);
void display(struct linklist *);
void f_insert();
void l_insert();
void m_insert();
void f_delet();
void l_delet();
void m_delet();

void main()
{
    int n;
    clrscr();

    /* Step 1: Create the first node.
       Why: The original lab program starts by creating at least one node. */
    start = (struct linklist *)malloc(sizeof(struct linklist));
    if(start == NULL)
    {
        printf("Memory allocation failed.");
        getch();
        return;
    }

    create(start);

    printf("\nCreated nodes are: ");
    display(start);

menu:
    /* Step 2: Show linked-list operations. */
    printf("\n1. Insert at first position");
    printf("\n2. Insert at last position");
    printf("\n3. Insert at desired position");
    printf("\n4. Delete first node");
    printf("\n5. Delete last node");
    printf("\n6. Delete desired position");
    printf("\n7. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &n);

    switch(n)
    {
        case 1:
            f_insert();
            display(start);
            goto menu;
        case 2:
            l_insert();
            display(start);
            goto menu;
        case 3:
            m_insert();
            display(start);
            goto menu;
        case 4:
            f_delet();
            display(start);
            goto menu;
        case 5:
            l_delet();
            display(start);
            goto menu;
        case 6:
            m_delet();
            display(start);
            goto menu;
        case 7:
            exit(0);
        default:
            printf("\nWrong choice.");
            goto menu;
    }
}

void create(struct linklist *ptr)
{
    char ch;

    /* Step 3: Fill one node at a time.
       Why: Each node stores data and a pointer to the next node. */
    do
    {
        printf("\nEnter node data: ");
        scanf("%d", &ptr->info);

        printf("Do you want to add another node? Press y: ");
        fflush(stdin);
        ch = getchar();

        if(ch == 'y' || ch == 'Y')
        {
            ptr->next = (struct linklist *)malloc(sizeof(struct linklist));
            if(ptr->next == NULL)
            {
                printf("Memory allocation failed.");
                ptr->next = NULL;
                return;
            }
            ptr = ptr->next;
        }
    }
    while(ch == 'y' || ch == 'Y');

    /* Step 4: Last node points to NULL to mark end of list. */
    ptr->next = NULL;
}

void display(struct linklist *ptr)
{
    /* Step 5: Traverse from start until NULL. */
    printf("\nLinked list contains: ");

    if(ptr == NULL)
    {
        printf("EMPTY");
        return;
    }

    while(ptr != NULL)
    {
        printf("%d", ptr->info);
        if(ptr->next != NULL)
            printf(" -> ");
        ptr = ptr->next;
    }
}

void f_insert()
{
    struct linklist *new1;

    /* Step 6: Allocate a new node and place it before start. */
    new1 = (struct linklist *)malloc(sizeof(struct linklist));
    if(new1 == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &new1->info);

    new1->next = start;
    start = new1;
}

void l_insert()
{
    struct linklist *new1, *ptr;

    /* Step 7: Create a node whose next pointer is NULL. */
    new1 = (struct linklist *)malloc(sizeof(struct linklist));
    if(new1 == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &new1->info);
    new1->next = NULL;

    if(start == NULL)
    {
        start = new1;
        return;
    }

    /* Step 8: Move to last node and connect new node. */
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new1;
}

void m_insert()
{
    struct linklist *ptr, *new1, *prev;
    int m, i;

    printf("Enter position to insert: ");
    scanf("%d", &m);

    if(m < 1)
    {
        printf("Invalid position.");
        return;
    }

    new1 = (struct linklist *)malloc(sizeof(struct linklist));
    if(new1 == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }

    printf("Enter data of new node: ");
    scanf("%d", &new1->info);

    /* Step 9: Position 1 is the same as first insertion. */
    if(m == 1)
    {
        new1->next = start;
        start = new1;
        return;
    }

    /* Step 10: Reach the node just before the requested position. */
    ptr = start;
    prev = NULL;
    i = 1;

    while(i < m && ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
        i++;
    }

    if(i != m || prev == NULL)
    {
        printf("Invalid position.");
        free(new1);
        return;
    }

    new1->next = ptr;
    prev->next = new1;
}

void f_delet()
{
    struct linklist *ptr;

    /* Step 11: Check empty list before deleting first node. */
    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    ptr = start;
    start = start->next;
    printf("\nDeleted node is %d\n", ptr->info);
    free(ptr);
}

void l_delet()
{
    struct linklist *ptr, *prev;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    /* Step 12: If only one node exists, make start NULL. */
    if(start->next == NULL)
    {
        printf("\nDeleted node is %d\n", start->info);
        free(start);
        start = NULL;
        return;
    }

    /* Step 13: Reach last node while keeping previous node. */
    prev = NULL;
    ptr = start;
    while(ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;
    printf("\nDeleted node is %d\n", ptr->info);
    free(ptr);
}

void m_delet()
{
    struct linklist *ptr, *prev;
    int m, i;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &m);

    if(m < 1)
    {
        printf("Invalid position.");
        return;
    }

    /* Step 14: Handle first node separately. */
    if(m == 1)
    {
        ptr = start;
        start = start->next;
        printf("\nDeleted node is %d\n", ptr->info);
        free(ptr);
        return;
    }

    /* Step 15: Find node at requested position. */
    ptr = start;
    prev = NULL;
    i = 1;

    while(i < m && ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
        i++;
    }

    if(ptr == NULL || i != m)
    {
        printf("Invalid position.");
        return;
    }

    prev->next = ptr->next;
    printf("\nDeleted node is %d\n", ptr->info);
    free(ptr);
}
