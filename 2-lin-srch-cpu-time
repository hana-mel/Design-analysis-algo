#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MIN 1

int linearSearch(int arr[], int n, int key) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() 
{
    int t = 2;
    int n, key, pos;
    int i, j;
    clock_t start, end;
    double cpu_time;

    start = clock();

    for (i = 1; i <= t; i++) 
    {
        printf("\nTest case %d\n", i);
        printf("Enter array size: ");
        scanf("%d", &n);

        int arr[n];
        srand(time(NULL) + i);

        for (j = 0; j < n; j++)
            arr[j] = rand() % (MAX - MIN + 1) + MIN;

        printf("Array elements:\n");
        for (j = 0; j < n; j++)
            printf("%d\n", arr[j]);

        printf("Enter key to search: ");
        scanf("%d", &key);

        pos = linearSearch(arr, n, key);

        if (pos != -1)
            printf("Key found at position %d\n", pos);
        else
            printf("Key not found\n");
    }

    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTotal CPU time taken = %f seconds\n", cpu_time);

    return 0;
}
