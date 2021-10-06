#include <iostream>
using namespace std;

void printStep(int *&step, int &n)
{
    for (int i = 0; i < n * n; ++i)
        cout << char(step[i] / n + 65) << step[i] % n + 1 << endl;
}

bool inChessboard(int x, int y, int &n)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n))
        return true;
    return false;
}

void tourOfKnight(int *&chessboard, int *&step, int &n, int index, int &s0, int si, bool &comeback)
{
    int numX, numY, opX, opY, xf, yf, sf;
    for (numX = 1; numX <= 2; ++numX)
        for (opX = 0; opX <= 1; ++opX)
            for (opY = 0; opY <= 1; ++opY)
            {
                if (comeback)
                    return;
                numY = 3 - numX;
                if (opX == 0)
                    xf = si / n + numX;
                else
                    xf = si / n - numX;
                if (opY == 0)
                    yf = si % n + numY;
                else
                    yf = si % n - numY;
                sf = xf * n + yf;
                if (sf == s0 && index == n * n - 1)
                {
                    step[index] = s0;
                    cout << "Let's go!\n";
                    printStep(step, n);
                    comeback = true;
                    return;
                }
                if (index < n * n && inChessboard(xf, yf, n) && sf != s0 && chessboard[sf] != 1)
                {
                    step[index] = sf;
                    chessboard[sf] = 1;
                    tourOfKnight(chessboard, step, n, index + 1, s0, sf, comeback);
                    chessboard[sf] = 0;
                }
            }
}

int main()
{
    int n;
    cin >> n;
    int *chessboard = new int[n * n];
    int *step = new int[n * n];
    for (int i = 0; i < n * n; ++i)
        step[i] = 0;
    int x, y;
    cin >> x >> y;
    int s0 = x * n + y;
    bool comeback = false;
    tourOfKnight(chessboard, step, n, 0, s0, s0, comeback);
    delete[] chessboard;
    delete[] step;
    return 0;
}