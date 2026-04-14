#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
#define MIN 1

void selectionSort(int a[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+ 1;j<n;j++)
        {
            if(a[min] > a[j])
                min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

int main()
{
    int sizes[10];
    clock_t start,end;
    double best,avg,worst;
    
    srand(time(NULL));
    for(int i =0;i<10;i++)
    {
        sizes[i] = rand() % (50000 - 50 + 1)+ 50;
    }
    FILE *fp = fopen("selection.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        return 1;
    }
    
    printf("--------------------------------------------------\n");
    printf("%-12s %-16s %-16s %-16s\n","Sizes","Best","Avg","Worst");
    printf("--------------------------------------------------\n");
    fprintf(fp,"--------------------------------------------------\n");
    fprintf(fp,"%-12s %-16s %-16s %-16s\n","Sizes","Best","Avg","Worst");
    fprintf(fp,"--------------------------------------------------\n");
    
    for(int s=0;s<10;s++)
    {
        int n = sizes[s];
        int *a = (int *)malloc(n * sizeof(int));
        
        if(a == NULL)
        {
            printf("Memory allocation failed");
            fclose(fp);
            return 1;
        }
        //Best
        for(int i =0;i<n;i++)
        {
            a[i] = i+ 1;
        }
        start = clock();
        selectionSort(a,n);
        end = clock();
        best = ((double)(end - start)) / CLOCKS_PER_SEC;
        //Worst
        for(int i =0;i<n;i++)
        {
            a[i] = n - i;
        }
        start = clock();
        selectionSort(a,n);
        end = clock();
        worst = ((double)(end - start)) / CLOCKS_PER_SEC;
        //Avg
        for(int i =0;i<n;i++)
        {
            a[i] = rand() % (MAX - MIN + 1)+ MIN;
        }
        start = clock();
        selectionSort(a,n);
        end = clock();
        avg = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%-12d %-16f %-16f %-16f\n",n,best,avg,worst);
        fprintf(fp,"%-12d %-16f %-16f %-16f\n",n,best,avg,worst);
        free(a);
        
    }
    printf("--------------------------------------------------\n");
    fprintf(fp,"--------------------------------------------------\n");
    fclose(fp);
    return 0;
}
