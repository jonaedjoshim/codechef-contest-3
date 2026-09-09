#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, f;
    cin >> x >> y >> f;

    int cost1 = x * 12;
    int cost2 = y * 12 + f;

    cout << min(cost1, cost2) << endl;

    return 0;
}