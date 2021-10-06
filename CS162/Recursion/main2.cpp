#include <iostream>
#include <string>
using namespace std;

void deleteOneElement(int *&arr, int n, int i)
{
    for (int j = i; j < n - 1; ++j)
        arr[j] = arr[j + 1];
}

int calculate(int *&array, int *&operatorArray, int numberOfElements)
{
    int n = numberOfElements;
    int *arr = new int[n];
    int *oprt = new int[n - 1];
    arr[0] = array[0];
    for (int i = 0; i < n - 1; ++i)
    {
        arr[i + 1] = array[i + 1];
        oprt[i] = operatorArray[i];
    }
    for (int i = 0; i < n - 1; ++i)
        if (oprt[i] == 2)
        {
            arr[i] = arr[i] * arr[i + 1];
            deleteOneElement(arr, n, i + 1);
            deleteOneElement(oprt, n - 1, i);
            --n;
            --i;
        }
        else if (oprt[i] == 3)
        {
            arr[i] = arr[i] / arr[i + 1];
            deleteOneElement(arr, n, i + 1);
            deleteOneElement(oprt, n - 1, i);
            --n;
            --i;
        }
    int ans = arr[0];
    for (int i = 0; i < n - 1; ++i)
        if (oprt[i] == 0)
            ans += arr[i + 1];
        else
            ans -= arr[i + 1];
    delete[] arr;
    delete[] oprt;
    return ans;
}

int *firstFillOperator(int *&arr, int *&oprt, int i, int n, int number)
{
    if (i < n - 1)
        for (int j = 0; j < 4; ++j)
        {
            oprt[i] = j;
            firstFillOperator(arr, oprt, i + 1, n, number);
            if (calculate(arr, oprt, n) == number)
                return oprt;
        }
    return nullptr;
}

void fillOperator(int *&arr, int *&oprt, int i, int n, int number)
{
    if (i < n - 1)
        for (int j = 0; j < 4; ++j)
        {
            oprt[i] = j;
            fillOperator(arr, oprt, i + 1, n, number);
        }
    else if (calculate(arr, oprt, n) == number)
    {
        cout << arr[0];
        for (int j = 0; j < n - 1; ++j)
        {
            if (oprt[j] == 0)
                cout << " + ";
            else if (oprt[j] == 1)
                cout << " - ";
            else if (oprt[j] == 2)
                cout << " * ";
            else
                cout << " / ";
            cout << arr[j + 1];
        }
        cout << " = " << number << endl;
    }
}

int main()
{
    int n, number;
    cout << "Enter n: ";
    cin >> n;
    int *arr = new int[n];
    int *oprt = new int[n - 1];
    for (int i = 0; i < n; ++i)
    {
        cout << "Input value: ";
        cin >> arr[i];
    }
    cout << "Enter a number: ";
    cin >> number;
    cout << "The first method: ";
    oprt = firstFillOperator(arr, oprt, 0, n, number);
    cout << arr[0];
    for (int j = 0; j < n - 1; ++j)
    {
        if (oprt[j] == 0)
            cout << " + ";
        else if (oprt[j] == 1)
            cout << " - ";
        else if (oprt[j] == 2)
            cout << " * ";
        else
            cout << " / ";
        cout << arr[j + 1];
    }
    cout << " = " << number << endl;
    cout << "All methods:\n";
    fillOperator(arr, oprt, 0, n, number);
    delete[] arr;
    delete[] oprt;
    return 0;
}