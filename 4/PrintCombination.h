#include <iostream>
#include <vector>

using namespace std;

void combine(int *arrPtr, int *temp, int start, int end, int index, int c)
{
    if (index == c)
    {
        for (int i = 0; i < c; i++)
        {
            cout << arrPtr[i];
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= end && end - i - 1 >= c - index; i++)
    {
        temp[index] = arrPtr[i];

        combine(arrPtr, temp, i + 1, end, index + 1, c);
    }
}

void PrintCombination(int *arrayPtr, int n, int c)
{
    int temp[c];

    combine(arrayPtr, temp, 0, n - 1, 0, c);
}
