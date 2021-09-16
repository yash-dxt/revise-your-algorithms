#include <algorithm>

using namespace std;

void countingSortBasic(int arr[], int n, int k)
{

    int cnt[k];

    for (int i = 0; i < k; i++)
    {
        cnt[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < cnt[i]; i++)
        {
            arr[index++] = i;
        }
    }
}

void countingSort(int arr[], int n, int k)
{
    int cnt[k];

    for (int i = 0; i < k; i++)
    {
        cnt[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
    }

    for (int i = 1; i < k; i++)
    {
        cnt[i] = cnt[i - 1] + cnt[i];
    }

    int res[n];

    for (int i = n - 1; i >= 0; i--)
    {
        res[cnt[arr[i]] - 1] = arr[i];
        cnt[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }
}