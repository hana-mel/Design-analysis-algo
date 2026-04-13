#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MIN 1
#define SIZE 2500

void bubbleSort(int arr[], int n) 
{
    int i, j, temp, flag;
    for (i = 0; i < n - 1; i++) 
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main() 
{
    int arr[SIZE];
    clock_t start, end;
    double best, worst, avg;

    // Best Case
    for (int i = 0; i < SIZE; i++)
        arr[i] = i + 1;
    start = clock();
    bubbleSort(arr, SIZE);
    end = clock();
    best = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Worst Case
    for (int i = 0; i < SIZE; i++)
        arr[i] = SIZE - i;
    start = clock();
    bubbleSort(arr, SIZE);
    end = clock();
    worst = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Average Case
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % (MAX - MIN + 1) + MIN;
    start = clock();
    bubbleSort(arr, SIZE);
    end = clock();
    avg = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print to screen
    printf("Best Time  - %f seconds\n", best);   
    printf("Worst Time - %f seconds\n", worst);
    printf("Avg Time   - %f seconds\n", avg);

    // Write results to file
    FILE *fp = fopen("results.txt", "w");
    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "Best Time  - %f seconds\n", best);
    fprintf(fp, "Worst Time - %f seconds\n", worst);
    fprintf(fp, "Avg Time   - %f seconds\n", avg);
    fclose(fp);

    printf("\nResults saved to results.txt\n");
    return 0;
}
