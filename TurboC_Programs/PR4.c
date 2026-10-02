/* Program 4: Quick Sort (Partition Exchange Sort) - Turbo C compatible */
#include<stdio.h>
#include<conio.h>

#define MAX 15

void quick_sort(int [], int, int);

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

    /* Step 2: Read input values. */
    printf("Enter elements in array:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &k[i]);

    /* Step 3: Sort complete range from 1 to n. */
    quick_sort(k, 1, n);

    /* Step 4: Display sorted values. */
    printf("Array sorted in ascending order: ");
    for(i = 1; i <= n; i++)
        printf("%d ", k[i]);

    getch();
}

void quick_sort(int k[], int lb, int ub)
{
    int i, j, temp, flag, key;

    /* Step 5: Continue only if sub-array has at least two elements. */
    if(lb < ub)
    {
        flag = 1;
        i = lb;
        j = ub + 1;
        key = k[lb];

        /* Step 6: Partition around the key value. */
        while(flag == 1)
        {
            i = i + 1;

            /* Bounds are checked first to avoid accessing outside the array. */
            while(i <= ub && k[i] < key)
                i = i + 1;

            j = j - 1;
            while(j >= lb && k[j] > key)
                j = j - 1;

            /* Step 7: Swap values that are on the wrong side of the key. */
            if(i < j)
            {
                temp = k[i];
                k[i] = k[j];
                k[j] = temp;
            }
            else
                flag = 0;
        }

        /* Step 8: Put key in its final correct position. */
        temp = k[lb];
        k[lb] = k[j];
        k[j] = temp;

        /* Step 9: Recursively sort left and right partitions. */
        quick_sort(k, lb, j - 1);
        quick_sort(k, j + 1, ub);
    }
}
