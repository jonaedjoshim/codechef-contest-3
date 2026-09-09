#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int dp[2][2];
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[1][0] = -1;
        dp[1][1] = -1;

        for (int i = 1; i < n; i++)
        {
            int ndp[2][2];
            ndp[0][0] = ndp[0][1] = ndp[1][0] = ndp[1][1] = -1;

            for (int sp = 0; sp < 2; sp++)
            {
                for (int sc = 0; sc < 2; sc++)
                {
                    if (dp[sp][sc] == -1)
                        continue;

                    for (int sn = 0; sn < 2; sn++)
                    {
                        bool ok;
                        if (sc == 1)
                        {
                            int c = 0;
                            if (i > 1 && sp == 1 && a[i - 1] == 1)
                                c++;
                            if (sn == 1 && a[i + 1] == 1)
                                c++;
                            ok = c < a[i];
                        }
                        else
                        {
                            int d = 0;
                            if (i > 1 && sp == 1)
                                d++;
                            if (sn == 1)
                                d++;
                            ok = d >= a[i];
                        }

                        if (ok)
                        {
                            int val = dp[sp][sc] + (sn == 1 ? 1 : 0);
                            if (val > ndp[sc][sn])
                                ndp[sc][sn] = val;
                        }
                    }
                }
            }

            dp[0][0] = ndp[0][0];
            dp[0][1] = ndp[0][1];
            dp[1][0] = ndp[1][0];
            dp[1][1] = ndp[1][1];
        }

        int best = -1;
        for (int sp = 0; sp < 2; sp++)
        {
            for (int sc = 0; sc < 2; sc++)
            {
                if (dp[sp][sc] == -1)
                    continue;

                bool ok;
                if (sc == 1)
                {
                    int c = 0;
                    if (n > 1 && sp == 1 && a[n - 1] == 1)
                        c++;
                    ok = c < a[n];
                }
                else
                {
                    int d = 0;
                    if (n > 1 && sp == 1)
                        d++;
                    ok = d >= a[n];
                }

                if (ok && dp[sp][sc] > best)
                    best = dp[sp][sc];
            }
        }

        cout << best << endl;
    }

    return 0;
}