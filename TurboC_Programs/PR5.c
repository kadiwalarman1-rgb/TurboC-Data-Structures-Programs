/* Program 5: Selection Sort - Turbo C compatible */
#include<stdio.h>
#include<conio.h>

#define MAX 10

void selection_sort(int [], int);

void main()
{
    int k[MAX + 1], n, i;
    clrscr();

    /* Step 1: Read size and values. */
    printf("How many elements (1-%d): ", MAX);
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid number of elements.");
        getch();
        return;
    }

    printf("Enter elements in array:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &k[i]);

    /* Step 2: Call selection sort. */
    selection_sort(k, n);
    getch();
}

void selection_sort(int k[], int n)
{
    int min_index, pass, j, i, temp;

    /* Step 3: Select one position at a time. */
    for(pass = 1; pass <= n - 1; pass++)
    {
        min_index = pass;

        /* Step 4: Find the smallest value in the unsorted part. */
        for(i = pass + 1; i <= n; i++)
        {
            if(k[i] < k[min_index])
                min_index = i;
        }

        /* Step 5: Put the smallest value at current pass position. */
        if(min_index != pass)
        {
            temp = k[pass];
            k[pass] = k[min_index];
            k[min_index] = temp;
        }
    }

    /* Step 6: Display sorted list. */
    printf("Sorted list is: ");
    for(j = 1; j <= n; j++)
        printf("%d ", k[j]);
}
