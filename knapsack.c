#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int weight;
    int profit;
    float ratio;
} Item;

// Function to swap items
void swap(Item *a, Item *b)
{
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort by ratio (descending)
void sortByRatio(Item items[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(items[j].ratio < items[j + 1].ratio)
                swap(&items[j], &items[j + 1]);
        }
    }
}

// Sort by weight (ascending)
void sortByWeight(Item items[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(items[j].weight > items[j + 1].weight)
                swap(&items[j], &items[j + 1]);
        }
    }
}

// Sort by profit (descending)
void sortByProfit(Item items[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(items[j].profit < items[j + 1].profit)
                swap(&items[j], &items[j + 1]);
        }
    }
}

// Fractional Knapsack function
float knapsack(Item items[], int n, int capacity)
{
    float totalProfit = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    return totalProfit;
}

int main()
{
    int n, capacity, choice;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter weight and profit of each item:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("\nChoose case:\n");
    printf("1. Sort by Ratio (Profit/Weight)\n");
    printf("2. Sort by Weight\n");
    printf("3. Sort by Profit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            sortByRatio(items, n);
            printf("\nSorted by Ratio\n");
            break;

        case 2:
            sortByWeight(items, n);
            printf("\nSorted by Weight\n");
            break;

        case 3:
            sortByProfit(items, n);
            printf("\nSorted by Profit\n");
            break;

        default:
            printf("Invalid choice\n");
            return 0;
    }

    float maxProfit = knapsack(items, n, capacity);

    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}
