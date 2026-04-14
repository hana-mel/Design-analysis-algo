#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define MIN 1

// Partition function
int partition(int a[], int low, int high)
{
    int pivot = a[high];   // choosing last element as pivot
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

// Quick Sort function
void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int sizes[10];
    clock_t start, end;
    double best, avg, worst;

    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        sizes[i] = rand() % (50000 - 50 + 1) + 50;
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

        // Best case (balanced partitions → roughly sorted)
        for(int i = 0; i < n; i++)
            a[i] = i + 1;

        start = clock();
        quickSort(a, 0, n - 1);
        end = clock();
        best = (double)(end - start) / CLOCKS_PER_SEC;

        // Worst case (already sorted for this pivot choice)
        for(int i = 0; i < n; i++)
            a[i] = i + 1;

        start = clock();
        quickSort(a, 0, n - 1);
        end = clock();
        worst = (double)(end - start) / CLOCKS_PER_SEC;

        // Average case (random)
        for(int i = 0; i < n; i++)
            a[i] = rand() % (MAX - MIN + 1) + MIN;

        start = clock();
        quickSort(a, 0, n - 1);
        end = clock();
        avg = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%-12d %-16f %-16f %-16f\n", n, best, avg, worst);

        free(a);
    }

    printf("--------------------------------------------------\n");

    return 0;
}
