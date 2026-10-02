/* Program 9: Radix Sort - Turbo C compatible */
#include<stdio.h>
#include<conio.h>

#define MAX 10

int get_max(int [], int);
void radix_sort(int [], int);

void main()
{
    int i, n, a[MAX];
    clrscr();

    /* Step 1: Read number of items. */
    printf("Enter the number of items to be sorted (1-%d): ", MAX);
    scanf("%d", &n);

    if(n < 1 || n > MAX)
    {
        printf("Invalid number of items.");
        getch();
        return;
    }

    /* Step 2: Read non-negative integers.
       Why: This simple decimal radix-sort version uses buckets 0 to 9. */
    printf("Enter non-negative items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] < 0)
        {
            printf("Negative numbers are not supported by this radix-sort version.");
            getch();
            return;
        }
    }

    /* Step 3: Sort numbers digit by digit. */
    radix_sort(a, n);

    /* Step 4: Display sorted result. */
    printf("\nSorted items: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    getch();
}

int get_max(int a[], int n)
{
    int max, i;
    max = a[0];

    /* Step 5: Find largest value.
       Why: Its digit count tells us how many radix passes are needed. */
    for(i = 1; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

void radix_sort(int a[], int n)
{
    int bucket[10][MAX];
    int bucket_count[10];
    int i, j, k, r, lar, pass, digit, divisor;

    lar = get_max(a, n);
    digit = 0;
    divisor = 1;

    /* Step 6: Count digits in largest value. */
    if(lar == 0)
        digit = 1;
    else
    {
        while(lar > 0)
        {
            digit++;
            lar = lar / 10;
        }
    }

    /* Step 7: Process one decimal digit in each pass. */
    for(pass = 0; pass < digit; pass++)
    {
        for(i = 0; i < 10; i++)
            bucket_count[i] = 0;

        /* Step 8: Put each number into the bucket of current digit. */
        for(i = 0; i < n; i++)
        {
            r = (a[i] / divisor) % 10;
            bucket[r][bucket_count[r]] = a[i];
            bucket_count[r]++;
        }

        /* Step 9: Collect buckets back in order 0 to 9. */
        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < bucket_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }

        divisor = divisor * 10;

        printf("After pass %d: ", pass + 1);
        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
}
