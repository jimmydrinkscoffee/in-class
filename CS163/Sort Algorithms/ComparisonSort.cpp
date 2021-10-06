#include <iostream>
#include <ctime>
using namespace std;

//  Insertion Sort

void InsertionSort(int *&arr, int &n)
{
    for (int i = 1; i < n; ++i)
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; --j)
            swap(arr[j], arr[j + 1]);
}

//  Selection Sort

void SelectionSort(int *&arr, int &n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minI = i;
        for (int j = i; j < n; ++j)
            if (arr[j] < arr[minI])
                minI = j;
        swap(arr[i], arr[minI]);
    }
}

//  Bubble Sort

void BubbleSort(int *&arr, int &n)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = n - 1; i > 0; --i)
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                sorted = false;
            }
    }
}

int main()
{
    srand(time(NULL));

    int n = rand() % 20;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    BubbleSort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}