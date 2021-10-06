#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

void MergeArray(int *&arr, int low, int middle, int high)
{
    int index = low;

    queue<int> q1, q2;
    for (int i = low; i <= middle; ++i)
        q1.push(arr[i]);
    for (int i = middle + 1; i <= high; ++i)
        q2.push(arr[i]);

    while (!q1.empty() && !q2.empty())
    {
        if (q1.front() < q2.front())
        {
            arr[index++] = q1.front();
            q1.pop();
        }
        else
        {
            arr[index++] = q2.front();
            q2.pop();
        }
    }

    while (!q1.empty())
    {
        arr[index++] = q1.front();
        q1.pop();
    }

    while (!q2.empty())
    {
        arr[index++] = q2.front();
        q2.pop();
    }
}

void MergeSort(int *&arr, int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;

        MergeSort(arr, low, middle);
        MergeSort(arr, middle + 1, high);

        MergeArray(arr, low, middle, high);
    }
}

int main()
{
    srand(time(NULL));

    int n = rand() % 20;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}