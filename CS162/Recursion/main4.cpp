#include <iostream>
using namespace std;

void allSorts(int *&arr, int index, bool *&used, int n, int k)
{
    if (k > 0)
        for (int i = 0; i < n; ++i)
            if (!used[i])
            {
                arr[index] = i + 1;
                used[i] = true;
                allSorts(arr, index + 1, used, n, k - 1);
                used[i] = false;
            }
            else
                continue;
    else
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    bool *used = new bool[n];
    for (int i = 0; i < n; ++i)
        used[i] = false;
    allSorts(arr, 0, used, n, n);
    return 0;
}