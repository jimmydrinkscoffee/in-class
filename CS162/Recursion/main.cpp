#include <iostream>
using namespace std;

void deleteDuplicated(int *&arr, int &n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n - 1; ++k)
                    arr[k] = arr[k + 1];
                --n;
                --j;
            }
}

void subSet(int *arr, int irr, int *&ans, int ins, int &n, int k)
{
    if (k > 0)
        for (int i = irr; i < n; ++i)
        {
            ans[ins] = arr[i];
            subSet(arr, i + 1, ans, ins + 1, n, k - 1);
        }
    else
    {
        cout << "{ ";
        for (int j = 0; j < ins; ++j)
            cout << ans[j] << " ";
        cout << "}\n";
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter your set:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Input value: ";
        cin >> arr[i];
    }
    cout << "Do you want the duplicated values (Yes: 1, No: 0)? Answer: ";
    int dlctOrNot;
    cin >> dlctOrNot;
    if (dlctOrNot == 0)
        deleteDuplicated(arr, n);
    cout << "All subsets:\n";
    for (int k = 0; k <= n; ++k)
    {
        int *ans = new int[k];
        subSet(arr, 0, ans, 0, n, k);
        delete[] ans;
    }
    delete[] arr;
    return 0;
}