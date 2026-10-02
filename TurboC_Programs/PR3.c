/* Program 3: Bubble Sort - Turbo C compatible */
#include<stdio.h>
#include<conio.h>

#define MAX 10

void bubble_sort(int [], int);

void main()
{
    int k[MAX + 1], n, i;
    clrscr();

    /* Step 1: Read array size. */
    printf("How many elements (1-%d): ", MAX);
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid number of elements.");
        getch();
        return;
    }

    /* Step 2: Read array elements. */
    printf("Enter elements in array:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &k[i]);

    /* Step 3: Sort the array by bubble sort. */
    bubble_sort(k, n);

    /* Step 4: Display final sorted array. */
    printf("Array sorted in ascending order: ");
    for(i = 1; i <= n; i++)
        printf("%d ", k[i]);

    getch();
}

void bubble_sort(int k[], int n)
{
    int temp, i, pass, last, exchs;
    last = n;

    /* Step 5: Perform passes over the unsorted part.
       Why: Each pass moves the largest remaining element to the end. */
    for(pass = 1; pass <= n - 1; pass++)
    {
        exchs = 0;

        /* Step 6: Compare adjacent pairs and swap when out of order. */
        for(i = 1; i <= last - 1; i++)
        {
            if(k[i] > k[i + 1])
            {
                temp = k[i];
                k[i] = k[i + 1];
                k[i + 1] = temp;
                exchs = exchs + 1;
            }
        }

        /* Step 7: Stop early if no swap happened.
           Why: No swap means the array is already sorted. */
        if(exchs == 0)
            return;

        last = last - 1;
    }
}
