#include <algorithm>

using namespace std;

void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int j = i;

        while (j > 0 && arr[j - 1] > value)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = value;
    }
}
