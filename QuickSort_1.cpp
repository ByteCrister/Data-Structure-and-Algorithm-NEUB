#include <stdio.h>

int Sort(int ar[], int low, int high)
{
    int i = low;
    int j = high + 1;
    int pivot = ar[low];

    while (i < j)
    {
        do
        {
            i++;
        } while (pivot > ar[i]);

        do
        {
            j--;
        } while (pivot < ar[j]);

        if (i < j)
        {
            int temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
        }
    }
    int temp = ar[low];
    ar[low] = ar[j];
    ar[j] = temp;

    return j;
}

void QuickSort(int ar[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = Sort(ar, low, high);
        QuickSort(ar, low, pivotIndex);
        QuickSort(ar, pivotIndex+1, high);
    }
}
int main()
{

    int mainArray[] = {9, 1, 5, 2, 7, 3, 8, 0};
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", mainArray[i]);
    }
    printf("\n");
    QuickSort(mainArray, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", mainArray[i]);
    }

    return 0;
}