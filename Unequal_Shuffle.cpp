#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int countA = 0, countB = 0;

        for (char c : a)
        {
            if (c == 'a')
                countA++;
        }

        for (char c : b)
        {
            if (c == 'a')
                countB++;
        }

        int totalA = countA + countB;

        if (totalA == n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}