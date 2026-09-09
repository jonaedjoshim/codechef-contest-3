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

        vector<int> a(n + 1), pos(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }

        int k = (n + 1) / 2;

        vector<int> lo(k + 1), hi(k + 1);

        lo[1] = hi[1] = pos[1];

        bool ok = true;

        for (int i = 2; i <= k; i++)
        {
            int len = 2 * i - 1;

            lo[i] = max({1, lo[i - 1] - 2, pos[i] - len + 1});
            hi[i] = min({n - len + 1, hi[i - 1], pos[i]});

            if (lo[i] > hi[i])
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << -1 << endl;
            continue;
        }

        vector<pair<int, int>> ans(k + 1);

        int l = 1;

        for (int i = k; i >= 1; i--)
        {
            int len = 2 * i - 1;
            int r = l + len - 1;

            ans[i] = {l, r};

            if (i > 1)
                l = max(lo[i - 1], l);
        }

        for (int i = 1; i <= k; i++)
            cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}