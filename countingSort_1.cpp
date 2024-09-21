#include <stdio.h>
int main()
{

    int MainArray[] = {5, 9, 2, 6, 1, 9, 3, 4, 5, 1, 2, 0, 0, 7, 7};

    int MainArraySize = sizeof(MainArray) / sizeof(MainArray[0]);

    int Max = MainArray[0];
    for (int i = 1; i < MainArraySize; i++)
    {
        if (Max < MainArray[i])
        {
            Max = MainArray[i];
        }
    }

    int CountArray[Max + 1];
    for (int i = 0; i < Max + 1; i++)
    {
        CountArray[i] = 0;
    }

    for (int i = 0; i < MainArraySize; i++)
    {
        ++CountArray[MainArray[i]];
    }

    int sum = 0;
    for (int i = 0; i < Max + 1; i++)
    {
        sum += CountArray[i];
        CountArray[i] = sum;
    }

    int outputArray[MainArraySize];

    for (int i = 0; i < MainArraySize; i++)
    {
        outputArray[--CountArray[MainArray[i]]] = MainArray[i];
    }

    for (int i = 0; i < MainArraySize; i++)
    {
        printf("%d ", outputArray[i]);
    }

    return 0;
}