/* Program 6: Insertion Sort - Turbo C compatible */
#include<stdio.h>
#include<conio.h>

#define MAX 10

void insertion_sort(int [], int);

void main()
{
    int k[MAX + 1], n, i;
    clrscr();

    /* Step 1: Read number of elements. */
    printf("How many elements (1-%d): ", MAX);
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid number of elements.");
        getch();
        return;
    }

    /* Step 2: Read the unsorted array. */
    printf("Enter elements in array:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &k[i]);

    /* Step 3: Sort using insertion sort. */
    insertion_sort(k, n);

    /* Step 4: Display sorted list. */
    printf("Sorted list is: ");
    for(i = 1; i <= n; i++)
        printf("%d ", k[i]);

    getch();
}

void insertion_sort(int k[], int n)
{
    int pass, j, temp;

    /* Step 5: Start from second element.
       Why: A single first element is already considered sorted. */
    for(pass = 2; pass <= n; pass++)
    {
        temp = k[pass];
        j = pass - 1;

        /* Step 6: Shift larger values one position to the right.
           Why: This creates the correct place for temp. */
        while(j >= 1 && temp < k[j])
        {
            k[j + 1] = k[j];
            j = j - 1;
        }

        /* Step 7: Insert temp into its correct position. */
        k[j + 1] = temp;
    }
}
