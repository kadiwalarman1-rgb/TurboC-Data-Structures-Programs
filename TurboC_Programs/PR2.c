/* Program 2: Binary Search - Turbo C compatible */
#include<stdio.h>
#include<conio.h>

#define MAX 15

void b_search(int [], int, int);

void main()
{
    int k[MAX + 1], n, i, x;
    clrscr();

    /* Step 1: Read number of elements.
       Why: Binary search needs the valid lower and upper limits. */
    printf("How many elements do you want in array (1-%d): ", MAX);
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid number of elements.");
        getch();
        return;
    }

    /* Step 2: Read elements in ASCENDING order.
       Why: Binary search works correctly only on a sorted list. */
    printf("Enter elements in ascending order:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &k[i]);

    /* Step 3: Verify that input is sorted.
       Why: This prevents binary search from giving a wrong result. */
    for(i = 2; i <= n; i++)
    {
        if(k[i] < k[i - 1])
        {
            printf("Error: Binary search requires ascending sorted data.");
            getch();
            return;
        }
    }

    /* Step 4: Read target value. */
    printf("Enter the element you want to search: ");
    scanf("%d", &x);

    b_search(k, n, x);
    getch();
}

void b_search(int k[], int n, int x)
{
    int low, high, mid;
    low = 1;
    high = n;

    /* Step 5: Repeatedly divide the search interval in half.
       Why: This is the main idea of binary search. */
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(x < k[mid])
            high = mid - 1;
        else if(x > k[mid])
            low = mid + 1;
        else
        {
            printf("Search is successful. Element found at location %d", mid);
            return;
        }
    }

    /* Step 6: low crossed high, so the value is not present. */
    printf("Search is unsuccessful");
}
