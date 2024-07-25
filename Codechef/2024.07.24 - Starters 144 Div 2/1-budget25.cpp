#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START144B/problems/BUDGET25

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> arr(n);
        for (auto &i : arr)
        {
            cin >> i;
        }

        sort(arr.rbegin(), arr.rend());

        long long excess = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= x)
            {
                ans++;
                excess += arr[i] - x;
            }
            else
            {
                int deficit = x - arr[i];
                if (excess >= deficit)
                {
                    ans++;
                    excess -= deficit;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
