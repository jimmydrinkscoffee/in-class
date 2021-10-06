#include <iostream>
using namespace std;

void N_Queen(int *&x, int &n, int m, bool &max);

int main()
{
    int n;
    cin >> n;
    int *x = new int[n];
    for (int i = 0; i < n; ++i)
        x[i] = -1;
    bool max = false;
    N_Queen(x, n, 0, max);
    for (int i = 0; i < n; ++i)
    {
        if (x[i] == -1)
            break;
        cout << "(" << i + 1 << ", " << x[i] + 1 << ") ";
    }
    cout << endl;
    delete[] x;
    return 0;
}

void N_Queen(int *&x, int &n, int m, bool &max)
{
    if (m < n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (max)
                return;
            if (m == 0)
            {
                x[m] = i;
                N_Queen(x, n, m + 1, max);
            }
            else
                for (int j = 0; j < m; ++j)
                    if (j - x[j] == m - i)
                        break;
                    else if (j + x[j] == m + i)
                        break;
                    else if (x[j] == i)
                        break;
                    else if (j == m - 1)
                    {
                        x[m] = i;
                        N_Queen(x, n, m + 1, max);
                    }
        }
    }
    else
        max = true;
}