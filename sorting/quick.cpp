#include <algorithm>

using namespace std;

int lomutoPartition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int j = l - 1;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j + 1], pivot);
    return j + 1;
}

int hoarePartition(int arr[], int l, int r)
{
    int i = l - 1;
    int j = r + 1;
    int pivot = arr[l];
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int p = lomutoPartition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

void quickSort2(int arr[], int l, int r)
{
    if (r > l)
    {
        int p = hoarePartition(arr, l, r);
        quickSort(arr, l, p);
        quickSort(arr, p + 1, r);
    }
}