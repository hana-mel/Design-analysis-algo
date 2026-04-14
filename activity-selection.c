#include<stdio.h>

typedef struct
{
    char name[5];
    int start;
    int finish;
} Activity;

// Swap function
void swap(Activity *a, Activity *b)
{
    Activity temp = *a;
    *a = *b;
    *b = temp;
}

// Sort activities by finish time (ascending)
void sortByFinish(Activity a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j].finish > a[j + 1].finish)
                swap(&a[j], &a[j + 1]);
        }
    }
}

int main()
{
    int n = 8;

    int start[8] = {1,0,1,4,2,5,3,4};
    int finish[8] = {3,4,2,6,9,8,5,7};

    Activity a[8];

    // Assign values and names
    for(int i = 0; i < n; i++)
    {
        sprintf(a[i].name, "A%d", i + 1);
        a[i].start = start[i];
        a[i].finish = finish[i];
    }

    // Sort by finish time
    sortByFinish(a, n);

    printf("Activities after sorting by finish time:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s: (%d, %d)\n", a[i].name, a[i].start, a[i].finish);
    }

    // Activity Selection
    printf("\nSelected Activities:\n");

    int i = 0;
    printf("%s ", a[i].name);

    for(int j = 1; j < n; j++)
    {
        if(a[j].start >= a[i].finish)
        {
            printf("%s ", a[j].name);
            i = j;
        }
    }

    return 0;
}
