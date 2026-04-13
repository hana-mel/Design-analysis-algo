#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 1

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int sizes[] = {2500, 10000, 50000, 150000};
    int numSizes = 4;
    clock_t start, end;
    double best, worst, avg;

    printf("----------------------------------------------------------\n");
    printf("%-12s %-16s %-16s %-16s\n", "Size", "Best case", "Worst case", "Avg case");
    printf("----------------------------------------------------------\n");

    for (int s = 0; s < numSizes; s++)
    {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
        
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        start = clock();
        insertionSort(arr, n);
        end = clock();
        best = ((double)(end - start)) / CLOCKS_PER_SEC;

        for (int i = 0; i < n; i++)
            arr[i] = n - i;
        start = clock();
        insertionSort(arr, n);
        end = clock();
        worst = ((double)(end - start)) / CLOCKS_PER_SEC;

        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (MAX - MIN + 1) + MIN;
        start = clock();
        insertionSort(arr, n);
        end = clock();
        avg = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%-12d %-16f %-16f %-16f\n", n, best, worst, avg);

        free(arr);
    }

    printf("----------------------------------------------------------\n");
    return 0;
}
