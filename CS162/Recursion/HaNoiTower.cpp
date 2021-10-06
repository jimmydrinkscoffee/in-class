#include <iostream>
using namespace std;

void HanoiTower(int n, char fromRod, char btwRod, char toRod)
{
    if (n == 1)
    {
        cout << fromRod << " -> " << toRod << endl;
        return;
    }
    HanoiTower(n - 1, fromRod, toRod, btwRod);
    cout << fromRod << " -> " << toRod << endl;
    HanoiTower(n - 1, btwRod, fromRod, toRod);
}

int main()
{
    int n;
    cin >> n;
    HanoiTower(n, 'A', 'B', 'C');
    return 0;
}