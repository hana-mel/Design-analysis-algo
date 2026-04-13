#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MIN 1

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int sizes[10];
    clock_t start, end;
    double best, worst, avg;

    FILE *fp;

    // Open file for writing
    fp = fopen("selection_sort_results.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    srand(time(NULL));

    // Generate 10 random sizes between 50 and 50000
    for (int i = 0; i < 10; i++)
    {
        sizes[i] = rand() % (50000 - 50 + 1) + 50;
    }

    // Write header to file
    fprintf(fp, "----------------------------------------------------------\n");
    fprintf(fp, "%-12s %-16s %-16s %-16s\n", "Size", "Best(sec)", "Worst(sec)", "Avg(sec)");
    fprintf(fp, "----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n");
    printf("%-12s %-16s %-16s %-16s\n", "Size", "Best(sec)", "Worst(sec)", "Avg(sec)");
    printf("----------------------------------------------------------\n");
    for (int s = 0; s < 10; s++)
    {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));

        if (arr == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(fp);
            return 1;
        }

        // Best Case
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        start = clock();
        selectionSort(arr, n);
        end = clock();
        best = (double)(end - start) / CLOCKS_PER_SEC;

        // Worst Case
        for (int i = 0; i < n; i++)
            arr[i] = n - i;

        start = clock();
        selectionSort(arr, n);
        end = clock();
        worst = (double)(end - start) / CLOCKS_PER_SEC;

        // Average Case
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (MAX - MIN + 1) + MIN;

        start = clock();
        selectionSort(arr, n);
        end = clock();
        avg = (double)(end - start) / CLOCKS_PER_SEC;

        // Write results to file
        fprintf(fp, "%-12d %-16f %-16f %-16f\n", n, best, worst, avg);
        printf("%-12d %-16f %-16f %-16f\n", n, best, worst, avg);

        free(arr);
    }

    fprintf(fp, "----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n");

    fclose(fp);

    printf("Results stored in 'selection_sort_results.txt'\n");

    return 0;
}
