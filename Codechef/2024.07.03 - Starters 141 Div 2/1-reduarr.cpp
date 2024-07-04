#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/START141B/problems/REDUARRAY?tab=statement

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> testcase(n);
        for (auto &i : testcase)
        {
            cin >> i;
        }
        long long ans = n;
        unordered_map<int, int> count;
        for (auto &i : testcase)
        {
            count[i]++;
        }
        for (auto &i : count)
        {
            ans = min(ans, (long long)(n - i.second) * i.first);
        }
        cout << ans << endl;
    }
    return 0;
}