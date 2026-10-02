/* Program 7: Shell Sort - Turbo C compatible */
#include<stdio.h>
#include<conio.h>

#define MAX 10

void shell_sort(int [], int);

void main()
{
    int k[MAX + 1], n, i;
    clrscr();

    /* Step 1: Read size and elements. */
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

    /* Step 2: Call Shell sort. */
    shell_sort(k, n);

    /* Step 3: Display final sorted list. */
    printf("Sorted list is: ");
    for(i = 1; i <= n; i++)
        printf("%d ", k[i]);

    getch();
}

void shell_sort(int k[], int n)
{
    int gap, i, swap, temp;

    /* Step 4: Start with half of array size as gap.
       Why: Shell sort first compares distant elements. */
    gap = n / 2;

    while(gap > 0)
    {
        swap = 1;

        /* Step 5: Repeat same gap until no swap occurs. */
        while(swap == 1)
        {
            swap = 0;

            for(i = 1; i <= n - gap; i++)
            {
                if(k[i] > k[i + gap])
                {
                    temp = k[i];
                    k[i] = k[i + gap];
                    k[i + gap] = temp;
                    swap = 1;
                }
            }
        }

        /* Step 6: Reduce the gap.
           Why: Final gap 1 finishes the array like insertion-style sorting. */
        gap = gap / 2;
    }
}
