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
        int cost, earn;
        cin >> cost >> earn;

        int answer = INT_MAX;

        for (int want = 1; want <= 200; want++)
        {
            if (want >= answer)
                break;

            long long totalSpent = 0;
            long long totalEarned = 0;
            int totalGpu = 0;

            for (int day = 1; day <= 400; day++)
            {
                if (totalGpu < want)
                {
                    totalGpu++;
                    totalSpent += cost;
                }

                totalEarned += 1LL * earn * totalGpu * totalGpu;

                if (totalEarned > totalSpent)
                {
                    answer = min(answer, day);
                    break;
                }

                if (day >= answer)
                    break;
            }
        }

        cout << answer << endl;
    }

    return 0;
}