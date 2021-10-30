#ifndef INTARRAY
#define INTARRAY

#include <iostream>
using namespace std;

class IntArray
{
private:
    int *array, size;

public:
    IntArray(int n = 0);
    IntArray(int arr[], int n);
    IntArray(const IntArray &arr);
    ~IntArray();

    friend istream &operator>>(istream &in, IntArray &arr);
    friend ostream &operator<<(ostream &out, const IntArray &arr);

    int &operator[](int i);

    explicit operator int() const;
};

#pragma region Define Methods
IntArray::IntArray(int n)
{
    size = n;
    array = new int[n];
    for (int i = 0; i < n; ++i)
        array[i] = 0;
}

IntArray::IntArray(int arr[], int n)
{
    size = n;
    array = new int[n];
    for (int i = 0; i < n; ++i)
        array[i] = arr[i];
}

IntArray::IntArray(const IntArray &arr)
{
    size = arr.size;
    array = new int[size];
    for (int i = 0; i < size; ++i)
        array[i] = arr.array[i];
}

IntArray::~IntArray()
{
    size = 0;
    delete[] array;
}

istream &operator>>(istream &in, IntArray &arr)
{
    in >> arr.size;
    arr.array = new int[arr.size];
    for (int i = 0; i < arr.size; ++i)
        in >> arr.array[i];
    return in;
}

ostream &operator<<(ostream &out, const IntArray &arr)
{
    for (int i = 0; i < arr.size; ++i)
        out << arr.array[i] << " ";
    return out;
}

int &IntArray::operator[](int i)
{
    return array[i];
}

IntArray::operator int() const
{
    int res = 0;
    for (int i = 0; i < size; ++i)
        res += array[i];
    return res;
}
#pragma endregion Define Methods
#endif