#include <iostream>
#include <ctime>
using namespace std;

void QuickSort(int *&arr, int low, int high)
{
    int pivot = arr[low], l = low, h = high;

    while (l < h)
    {
        while (arr[l] < pivot)
            ++l;
        while (arr[h] > pivot)
            --h;
        if (l <= h)
        {
            swap(arr[l], arr[h]);
            ++l;
            --h;
        }
    }

    if (low < h)
        QuickSort(arr, low, h);
    if (high > l)
        QuickSort(arr, l, high);
}

int main()
{
    srand(time(NULL));

    int n = rand() % 20;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}