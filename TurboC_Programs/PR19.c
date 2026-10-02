/* Program 19: Binary Search Tree Operations - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    struct node *lptr;
    int info;
    struct node *rptr;
};

struct node *t;
struct node *loc;
struct node *par;
int item;

struct node *create(int, struct node *);
void display(int, struct node *);
void preorder(struct node *);
void postorder(struct node *);
void inorder(struct node *);
void search(struct node *);
void insert();
void delet();
void casea(struct node *, struct node *);
void caseb(struct node *, struct node *);

void main()
{
    int info, choice;
    char ch;
    clrscr();
    t = NULL;

    /* Step 1: Create the initial BST.
       Why: Each value is placed left if smaller and right otherwise. */
    printf("Create the binary search tree.\n");
    do
    {
        printf("Enter node info: ");
        scanf("%d", &info);
        t = create(info, t);

        printf("\nCurrent tree:\n");
        display(1, t);

        printf("\nDo you want to add more nodes? Press y: ");
        fflush(stdin);
        ch = getchar();
    }
    while(ch == 'y' || ch == 'Y');

menu:
    /* Step 2: Show BST operation menu. */
    printf("\n1. Preorder traversal");
    printf("\n2. Postorder traversal");
    printf("\n3. Inorder traversal");
    printf("\n4. Insert");
    printf("\n5. Delete");
    printf("\n6. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nPreorder traversal: ");
            preorder(t);
            goto menu;
        case 2:
            printf("\nPostorder traversal: ");
            postorder(t);
            goto menu;
        case 3:
            printf("\nInorder traversal: ");
            inorder(t);
            goto menu;
        case 4:
            insert();
            printf("\nTree after insertion:\n");
            display(1, t);
            goto menu;
        case 5:
            delet();
            printf("\nTree after deletion:\n");
            display(1, t);
            goto menu;
        case 6:
            exit(0);
        default:
            printf("\nWrong choice.");
            goto menu;
    }
}

struct node *create(int info, struct node *nod)
{
    /* Step 3: Allocate a node when an empty tree position is reached. */
    if(nod == NULL)
    {
        nod = (struct node *)malloc(sizeof(struct node));
        if(nod == NULL)
        {
            printf("Memory allocation failed.");
            return NULL;
        }

        nod->info = info;
        nod->lptr = NULL;
        nod->rptr = NULL;
        return nod;
    }

    /* Step 4: Recursively choose left or right subtree. */
    if(info < nod->info)
        nod->lptr = create(info, nod->lptr);
    else
        nod->rptr = create(info, nod->rptr);

    return nod;
}

void preorder(struct node *nod)
{
    /* Step 5: Preorder = Root, Left, Right. */
    if(nod != NULL)
    {
        printf("%d ", nod->info);
        preorder(nod->lptr);
        preorder(nod->rptr);
    }
}

void postorder(struct node *nod)
{
    /* Step 6: Postorder = Left, Right, Root. */
    if(nod != NULL)
    {
        postorder(nod->lptr);
        postorder(nod->rptr);
        printf("%d ", nod->info);
    }
}

void inorder(struct node *nod)
{
    /* Step 7: Inorder = Left, Root, Right.
       Why: For BST this prints values in sorted order. */
    if(nod != NULL)
    {
        inorder(nod->lptr);
        printf("%d ", nod->info);
        inorder(nod->rptr);
    }
}

void display(int level, struct node *p)
{
    int i;

    if(p != NULL)
    {
        display(level + 1, p->rptr);

        for(i = 1; i < level; i++)
            printf("   ");
        printf("%d\n", p->info);

        display(level + 1, p->lptr);
    }
}

void search(struct node *root)
{
    struct node *p, *parent;

    /* Step 8: Search keeps both current node and its parent.
       Why: Insert and delete need the parent link. */
    loc = NULL;
    par = NULL;
    p = root;
    parent = NULL;

    while(p != NULL)
    {
        if(item == p->info)
        {
            loc = p;
            par = parent;
            return;
        }

        parent = p;
        if(item < p->info)
            p = p->lptr;
        else
            p = p->rptr;
    }

    par = parent;
}

void insert()
{
    struct node *new1;

    printf("Enter item to insert: ");
    scanf("%d", &item);

    search(t);

    /* Step 9: Do not insert a duplicate value. */
    if(loc != NULL)
    {
        printf("Item is already in the tree.\n");
        return;
    }

    new1 = (struct node *)malloc(sizeof(struct node));
    if(new1 == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }

    new1->info = item;
    new1->lptr = NULL;
    new1->rptr = NULL;

    /* Step 10: Attach new node to parent or make it new root. */
    if(par == NULL)
        t = new1;
    else if(item < par->info)
        par->lptr = new1;
    else
        par->rptr = new1;
}

void casea(struct node *node_to_delete, struct node *parent)
{
    struct node *child;

    /* Step 11: Case A handles a leaf or a node with one child. */
    if(node_to_delete->lptr == NULL && node_to_delete->rptr == NULL)
        child = NULL;
    else if(node_to_delete->lptr != NULL)
        child = node_to_delete->lptr;
    else
        child = node_to_delete->rptr;

    if(parent == NULL)
        t = child;
    else if(node_to_delete == parent->lptr)
        parent->lptr = child;
    else
        parent->rptr = child;

    free(node_to_delete);
}

void caseb(struct node *node_to_delete, struct node *parent)
{
    struct node *suc, *parsuc;

    /* Step 12: Case B handles a node with two children.
       Why: We replace it with its inorder successor. */
    parsuc = node_to_delete;
    suc = node_to_delete->rptr;

    while(suc->lptr != NULL)
    {
        parsuc = suc;
        suc = suc->lptr;
    }

    /* Step 13: Detach successor from its old position. */
    if(parsuc != node_to_delete)
    {
        parsuc->lptr = suc->rptr;
        suc->rptr = node_to_delete->rptr;
    }

    /* Step 14: Successor takes deleted node's left subtree. */
    suc->lptr = node_to_delete->lptr;

    /* Step 15: Connect successor to deleted node's parent or root. */
    if(parent == NULL)
        t = suc;
    else if(node_to_delete == parent->lptr)
        parent->lptr = suc;
    else
        parent->rptr = suc;

    free(node_to_delete);
}

void delet()
{
    printf("Enter item to delete: ");
    scanf("%d", &item);

    search(t);

    /* Step 16: Stop if item is not present. */
    if(loc == NULL)
    {
        printf("Item is not in the tree.\n");
        return;
    }

    /* Step 17: Choose deletion case based on number of children. */
    if(loc->lptr != NULL && loc->rptr != NULL)
        caseb(loc, par);
    else
        casea(loc, par);

    printf("Item deleted successfully.\n");
}
