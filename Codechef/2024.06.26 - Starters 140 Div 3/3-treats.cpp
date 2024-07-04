#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/START140C/problems/TREATS

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> candle(n), chocolate(n);
        for (auto &i : candle)
        {
            cin >> i;
        }
        for (auto &i : chocolate)
        {
            cin >> i;
        }
        unordered_map<int, int> count;
        for (auto &i : chocolate)
        {
            i %= m;
            count[i]++;
        }
        long long ans = 0;
        for (auto &i : candle)
        {
            i %= m;
            if (count.find((m - i) % m) != count.end())
            {
                ans += count[(m - i) % m];
            }
        }
        cout << ans << endl;
    }
    return 0;
}