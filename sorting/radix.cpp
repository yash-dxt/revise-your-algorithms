#include <algorithm>

using namespace std;

void radixSort(int arr[], int n)
{

    int maxInArray = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxInArray)
        {
            maxInArray = arr[i];
        }
    }

    for (int x = 1; maxInArray / x > 0; x *= 10)
    {
        countingSort(arr, n, x);
    }
}

void countingSort(int arr[], int n, int k)
{
    int cnt[10];

    for (int i = 0; i < 10; i++)
    {
        cnt[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cnt[(arr[i] / k) % 10]++;
    }

    for (int i = 1; i < k; i++)
    {
        cnt[i] = cnt[i - 1] + cnt[i];
    }

    int res[n];

    for (int i = n - 1; i >= 0; i--)
    {
        res[cnt[(arr[i] / k) % 10] - 1] = arr[i];
        cnt[(arr[i] / k) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }
}