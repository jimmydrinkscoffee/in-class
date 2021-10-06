#include <iostream>
#include <ctime>
using namespace std;

void DownHeap(int *&arr, int &n, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, iSwap = i;
    if (left < n && arr[left] > arr[iSwap])
        iSwap = left;
    if (right < n && arr[right] > arr[iSwap])
        iSwap = right;
    if (iSwap != i)
    {
        swap(arr[i], arr[iSwap]);
        DownHeap(arr, n, iSwap);
    }
}

void BuildHeap(int *&arr, int &n)
{
    for (int i = n / 2; i >= 0; --i)
        DownHeap(arr, n, i);
}

void HeapSort(int *&arr, int &n)
{
    BuildHeap(arr, n);
    for (int i = n - 1; i >= 0; --i)
    {
        swap(arr[i], arr[0]);
        DownHeap(arr, i, 0);
    }
}

int main()
{
    srand(time(NULL));

    int n = rand() % 20;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    HeapSort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}