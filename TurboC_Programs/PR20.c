/* Program 20: Graph Traversal using BFS and DFS - Turbo C compatible */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 10

/* MAX+1 is used because vertices are numbered from 1 to MAX. */
int adj[MAX + 1][MAX + 1];
int visited[MAX + 1];
int queue[MAX + 1];
int front = 0, rear = 0;

void add_edge(int, int);
void BFS(int, int);
void DFS(int, int);
void dfsdetail(int, int);

void add_edge(int u, int v)
{
    /* Step 4: Store an undirected edge in both directions. */
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void BFS(int start, int n)
{
    int i, current;

    front = 0;
    rear = 0;

    /* Step 6: Mark every vertex unvisited before BFS. */
    for(i = 1; i <= n; i++)
        visited[i] = 0;

    /* Step 7: Mark start visited and put it into queue. */
    visited[start] = 1;
    rear++;
    queue[rear] = start;

    printf("BFS Traversal: ");

    /* Step 8: Remove one vertex at a time and visit its unvisited neighbors. */
    while(front != rear)
    {
        front++;
        current = queue[front];
        printf("%d ", current);

        for(i = 1; i <= n; i++)
        {
            if(adj[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                rear++;
                queue[rear] = i;
            }
        }
    }
    printf("\n");
}

void dfsdetail(int v, int n)
{
    int i;

    /* Step 10: Mark current vertex visited and print it. */
    visited[v] = 1;
    printf("%d ", v);

    /* Step 11: Recursively visit each unvisited adjacent vertex. */
    for(i = 1; i <= n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
            dfsdetail(i, n);
    }
}

void DFS(int start, int n)
{
    int i;

    /* Step 9: Clear visited array before DFS. */
    for(i = 1; i <= n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfsdetail(start, n);
    printf("\n");
}

void main()
{
    int n, e, u, v, choice, start;
    int i, j;
    clrscr();

    /* Step 1: Read number of vertices and keep it inside array limit. */
    printf("Enter number of vertices (1-%d): ", MAX);
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid number of vertices.");
        getch();
        return;
    }

    /* Step 2: Initialize adjacency matrix to zero.
       Why: Zero means no edge is present initially. */
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            adj[i][j] = 0;

    /* Step 3: Read graph edges. */
    printf("Enter number of edges: ");
    scanf("%d", &e);

    if(e < 0 || e > (n * (n - 1)) / 2)
    {
        printf("Invalid number of edges for a simple undirected graph.");
        getch();
        return;
    }

    for(i = 1; i <= e; i++)
    {
        printf("Enter edge %d (u v): ", i);
        scanf("%d %d", &u, &v);

        if(u < 1 || u > n || v < 1 || v > n)
        {
            printf("Invalid edge. Enter vertices between 1 and %d.\n", n);
            i--;
            continue;
        }

        add_edge(u, v);
    }

    do
    {
        /* Step 5: Let the user choose BFS or DFS. */
        printf("\n1. BFS");
        printf("\n2. DFS");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1 || choice == 2)
        {
            printf("Enter starting vertex (1 to %d): ", n);
            scanf("%d", &start);

            if(start < 1 || start > n)
            {
                printf("Invalid starting vertex.\n");
                continue;
            }

            if(choice == 1)
                BFS(start, n);
            else
                DFS(start, n);
        }
        else if(choice != 3)
            printf("Wrong choice.\n");
    }
    while(choice != 3);

    getch();
}
