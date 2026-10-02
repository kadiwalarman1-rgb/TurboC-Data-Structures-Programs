/* Program 1: Linear Search - Turbo C compatible */
#include<stdio.h>
#include<conio.h>

#define MAX 10

void l_search(int [], int, int);

void main()
{
    int k[MAX + 1], n, i, x;
    clrscr();

    /* Step 1: Read number of elements.
       Why: We must know how many valid array positions will be searched. */
    printf("How many elements do you want in array (1-%d): ", MAX);
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid number of elements.");
        getch();
        return;
    }

    /* Step 2: Read elements using positions 1 to n.
       Why: The college algorithm uses 1-based indexing. */
    printf("Enter elements:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &k[i]);

    /* Step 3: Read the value to search.
       Why: Linear search compares this value with each array element. */
    printf("Enter the element you want to search: ");
    scanf("%d", &x);

    /* Step 4: Call linear search.
       Why: Searching logic is kept in a separate function. */
    l_search(k, n, x);

    getch();
}

void l_search(int k[], int n, int x)
{
    int flag, loc;
    flag = 1;

    /* Step 5: Check every element from first to last.
       Why: Linear search works sequentially and does not require sorting. */
    for(loc = 1; loc <= n; loc++)
    {
        if(k[loc] == x)
        {
            printf("Search is successful. Element found at location %d", loc);
            flag = 0;
            break;
        }
    }

    /* Step 6: If flag is still 1, no match was found.
       Why: This reports unsuccessful search after checking the full list. */
    if(flag == 1)
        printf("Search is unsuccessful");
}
