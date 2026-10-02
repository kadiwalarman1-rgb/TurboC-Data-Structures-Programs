/* Program 8: Merge Sort - Turbo C compatible */
#include<stdio.h>
#include<conio.h>

#define MAX 15

int a[MAX + 1];

void merge(int, int, int);
void mergesort(int, int);

void merge(int low, int mid, int high)
{
    int l1, l2, i;
    int b[MAX + 1];

    l1 = low;
    l2 = mid + 1;
    i = low;

    /* Step 4: Compare both sorted halves.
       Why: The smaller current value is copied first into temporary array. */
    while(l1 <= mid && l2 <= high)
    {
        if(a[l1] <= a[l2])
        {
            b[i] = a[l1];
            l1++;
        }
        else
        {
            b[i] = a[l2];
            l2++;
        }
        i++;
    }

    /* Step 5: Copy any remaining values from left half. */
    while(l1 <= mid)
    {
        b[i] = a[l1];
        i++;
        l1++;
    }

    /* Step 6: Copy any remaining values from right half. */
    while(l2 <= high)
    {
        b[i] = a[l2];
        i++;
        l2++;
    }

    /* Step 7: Copy merged result back into original array. */
    for(i = low; i <= high; i++)
        a[i] = b[i];
}

void mergesort(int low, int high)
{
    int mid;

    /* Step 3: Divide array until each part contains one element. */
    if(low < high)
    {
        mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

void main()
{
    int i, n;
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
        scanf("%d", &a[i]);

    /* Step 2: Sort complete array recursively. */
    mergesort(1, n);

    /* Step 8: Display final sorted list. */
    printf("Sorted list is: ");
    for(i = 1; i <= n; i++)
        printf("%d ", a[i]);

    getch();
}
