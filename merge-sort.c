#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define MIN 1

// Merge function
void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int *temp = (int *)malloc((r - l + 1) * sizeof(int));

    while(i <= m && j <= r)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= m)
        temp[k++] = a[i++];

    while(j <= r)
        temp[k++] = a[j++];

    for(i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];

    free(temp);
}

// Merge Sort function
void mergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int sizes[10];
    clock_t start, end;
    double best, avg, worst;

    srand(time(NULL));

    // Generate random sizes (500 to 50000)
    for(int i = 0; i < 10; i++)
    {
        sizes[i] = rand() % (50000 - 500 + 1) + 500;
    }

    printf("--------------------------------------------------\n");
    printf("%-12s %-16s %-16s %-16s\n","Size","Best","Avg","Worst");
    printf("--------------------------------------------------\n");

    for(int s = 0; s < 10; s++)
    {
        int n = sizes[s];
        int *a = (int *)malloc(n * sizeof(int));

        if(a == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        // Best case (sorted)
        for(int i = 0; i < n; i++)
            a[i] = i + 1;

        start = clock();
        mergeSort(a, 0, n - 1);
        end = clock();
        best = (double)(end - start) / CLOCKS_PER_SEC;

        // Worst case (reverse sorted)
        for(int i = 0; i < n; i++)
            a[i] = n - i;

        start = clock();
        mergeSort(a, 0, n - 1);
        end = clock();
        worst = (double)(end - start) / CLOCKS_PER_SEC;

        // Average case (random)
        for(int i = 0; i < n; i++)
            a[i] = rand() % (MAX - MIN + 1) + MIN;

        start = clock();
        mergeSort(a, 0, n - 1);
        end = clock();
        avg = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%-12d %-16f %-16f %-16f\n", n, best, avg, worst);

        free(a);
    }

    printf("--------------------------------------------------\n");

    return 0;
}
