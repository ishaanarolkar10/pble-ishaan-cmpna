#include <stdio.h>

typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

void merge(Item a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    Item temp[100];

    while (i <= mid && j <= high) {
        if (a[i].ratio >= a[j].ratio)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(Item a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int n, capacity;
    Item items[100];
    float maxProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    mergeSort(items, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            maxProfit += items[i].profit;
        } else {
            maxProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", maxProfit);

    return 0;
}
