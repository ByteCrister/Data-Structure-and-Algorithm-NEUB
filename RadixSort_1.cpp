#include <stdio.h>
int A = 10, B = 1;
void RadixSort(int mainArray[], int size)
{
    int countArray[10];
    for (int i = 0; i < 10; i++)
    {
        countArray[i] = 0;
    }

    for (int i = 0; i<size; i++)
    {
        ++countArray[((mainArray[i] % A) / B)];
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += countArray[i];
        countArray[i] = sum;
    }

    int outputArray[size];
    for (int i = size - 1; i >= 0; i--)
    {
        outputArray[--countArray[((mainArray[i] % A) / B)]] = mainArray[i];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        mainArray[i] = outputArray[i];
    }

    A *= 10;
    B *= 10;
}

int maxDigit(int n)
{
    int i = 0;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return i;
}

int maxNumber(int ar[], int n)
{
    int max = ar[0];
    for (int i = 1; i < n; i++)
    {
        if (max < ar[i])
        {
            max = ar[i];
        }
    }

    return max;
}
int main()
{
    int MainArray[] = {303, 311, 32, 885, 111, 100, 99, 44, 20};

    int size = sizeof(MainArray) / sizeof(MainArray[0]);
    int max = maxNumber(MainArray, size);
    printf("%d\n",max);

    int loop = maxDigit(max);
    printf("%d\n",loop);
    for (int i = 1; i <= loop; i++)
    {
        RadixSort(MainArray, size);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", MainArray[i]);
    }

    return 0;
}