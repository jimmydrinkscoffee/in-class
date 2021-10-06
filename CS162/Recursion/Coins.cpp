#include <iostream>
using namespace std;

int minimumCoins(int *&c, int &n, int i, int m)
{
    if (m == 0)
        return 0;
    if (i == n)
        return INT32_MIN;
    int min = INT32_MAX;
    for (int j = 0; j <= m / c[i]; ++j)
    {
        int tmp = j + minimumCoins(c, n, i + 1, m - j * c[i]);
        if (tmp > 0 && tmp < min)
            min = tmp;
    }
    return min;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int *c = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Coin " << i + 1 << " = ";
        cin >> c[i];
    }
    int m;
    cout << "m = ";
    cin >> m;
    cout << "The minimum number of coins: " << minimumCoins(c, n, 0, m) << endl;
    delete[] c;
    return 0;
}