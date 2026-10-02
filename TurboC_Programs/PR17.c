/* Program 17: Doubly Linked List Operations - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct dlist
{
    struct dlist *prev;
    int info;
    struct dlist *next;
};

struct dlist *l, *r;

void create(struct dlist *);
void display_l(struct dlist *);
void display_r(struct dlist *);
void finsert();
void linsert();
void deinsert();
void fdelete();
void ldelete();
void mdelete();

void main()
{
    int n;
    clrscr();

    /* Step 1: Allocate first node.
       Why: l points to first node and r will point to last node. */
    l = (struct dlist *)malloc(sizeof(struct dlist));
    if(l == NULL)
    {
        printf("Memory allocation failed.");
        getch();
        return;
    }

    l->prev = NULL;
    create(l);

    printf("\nForward traversal: ");
    display_l(l);
    printf("\nBackward traversal: ");
    display_r(r);

menu:
    /* Step 2: Show doubly-linked-list operation menu. */
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
            finsert();
            display_l(l);
            goto menu;
        case 2:
            linsert();
            display_l(l);
            goto menu;
        case 3:
            deinsert();
            display_l(l);
            goto menu;
        case 4:
            fdelete();
            display_l(l);
            goto menu;
        case 5:
            ldelete();
            display_l(l);
            goto menu;
        case 6:
            mdelete();
            display_l(l);
            goto menu;
        case 7:
            exit(0);
        default:
            printf("\nWrong choice.");
            goto menu;
    }
}

void create(struct dlist *ptr)
{
    char ch;

    /* Step 3: Create nodes and connect both next and prev links. */
    do
    {
        printf("\nEnter node data: ");
        scanf("%d", &ptr->info);

        printf("Do you want to continue? Press y: ");
        fflush(stdin);
        ch = getchar();

        if(ch == 'y' || ch == 'Y')
        {
            ptr->next = (struct dlist *)malloc(sizeof(struct dlist));
            if(ptr->next == NULL)
            {
                printf("Memory allocation failed.");
                ptr->next = NULL;
                r = ptr;
                return;
            }
            ptr->next->prev = ptr;
            ptr = ptr->next;
        }
    }
    while(ch == 'y' || ch == 'Y');

    /* Step 4: Last node has no next node; save it in r. */
    ptr->next = NULL;
    r = ptr;
}

void display_l(struct dlist *ptr)
{
    printf("\nList: ");
    if(ptr == NULL)
    {
        printf("EMPTY");
        return;
    }

    /* Step 5: Forward traversal follows next pointers. */
    while(ptr != NULL)
    {
        printf("%d", ptr->info);
        if(ptr->next != NULL)
            printf(" <-> ");
        ptr = ptr->next;
    }
}

void display_r(struct dlist *ptr)
{
    printf("\nReverse list: ");
    if(ptr == NULL)
    {
        printf("EMPTY");
        return;
    }

    /* Step 6: Backward traversal follows prev pointers. */
    while(ptr != NULL)
    {
        printf("%d", ptr->info);
        if(ptr->prev != NULL)
            printf(" <-> ");
        ptr = ptr->prev;
    }
}

void finsert()
{
    struct dlist *new1;

    new1 = (struct dlist *)malloc(sizeof(struct dlist));
    if(new1 == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &new1->info);

    /* Step 7: New node becomes first; old first points back to it. */
    new1->prev = NULL;
    new1->next = l;

    if(l != NULL)
        l->prev = new1;
    else
        r = new1;

    l = new1;
}

void linsert()
{
    struct dlist *new1;

    new1 = (struct dlist *)malloc(sizeof(struct dlist));
    if(new1 == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &new1->info);

    /* Step 8: New node becomes last and links back to old last. */
    new1->next = NULL;
    new1->prev = r;

    if(r != NULL)
        r->next = new1;
    else
        l = new1;

    r = new1;
}

void deinsert()
{
    struct dlist *ptr, *new1;
    int m, i;

    printf("Enter position to insert: ");
    scanf("%d", &m);

    if(m < 1)
    {
        printf("Invalid position.");
        return;
    }

    if(m == 1)
    {
        finsert();
        return;
    }

    /* Step 9: Move ptr to the node currently at requested position. */
    ptr = l;
    i = 1;
    while(i < m && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    /* Position exactly after last node means append at end. */
    if(ptr == NULL)
    {
        if(i == m && r != NULL)
        {
            linsert();
            return;
        }
        printf("Invalid position.");
        return;
    }

    new1 = (struct dlist *)malloc(sizeof(struct dlist));
    if(new1 == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }

    printf("Enter data of new node: ");
    scanf("%d", &new1->info);

    /* Step 10: Connect new node in both directions. */
    new1->next = ptr;
    new1->prev = ptr->prev;
    ptr->prev->next = new1;
    ptr->prev = new1;
}

void fdelete()
{
    struct dlist *ptr;

    /* Step 11: Check empty list before deleting first node. */
    if(l == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    ptr = l;
    printf("\nDeleted node is %d\n", ptr->info);

    l = l->next;
    if(l != NULL)
        l->prev = NULL;
    else
        r = NULL;

    free(ptr);
}

void ldelete()
{
    struct dlist *ptr;

    if(r == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    /* Step 12: Remove last node and move r one node left. */
    ptr = r;
    printf("\nDeleted node is %d\n", ptr->info);

    r = r->prev;
    if(r != NULL)
        r->next = NULL;
    else
        l = NULL;

    free(ptr);
}

void mdelete()
{
    struct dlist *ptr;
    int m, i;

    if(l == NULL)
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

    /* Step 13: Locate the exact node to delete. */
    ptr = l;
    i = 1;
    while(i < m && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    if(ptr == NULL || i != m)
    {
        printf("Invalid position.");
        return;
    }

    if(ptr == l)
    {
        fdelete();
        return;
    }

    if(ptr == r)
    {
        ldelete();
        return;
    }

    /* Step 14: Bypass the middle node in both directions. */
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    printf("\nDeleted node is %d\n", ptr->info);
    free(ptr);
}
