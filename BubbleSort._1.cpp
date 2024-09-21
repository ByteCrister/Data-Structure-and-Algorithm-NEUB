#include <stdio.h>
void BubbleSort(int ar[], int n)
{

    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if(ar[min]>ar[j]){
                min=j;
            }
        }
        int temp = ar[min];
        ar[min] = ar[i];
        ar[i] = temp;
    }
}
int main()
{

    printf("Enter N : ");
    int n;
    scanf("%d", &n);

    int ar[n];
    for (int i = 0; i < n; i++)
    {
        printf("[%d] -> ", i);
        scanf("%d", &ar[i]);
    }

    printf("Before sort-> ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }

    BubbleSort(ar, n);

    printf("After sort-> ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}