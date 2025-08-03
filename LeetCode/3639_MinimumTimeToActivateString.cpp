#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-time-to-activate-string/

class Solution
{
public:
#define ll long long
    int minTime(string s, vector<int> &order, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = order.size();
        ll total = 1LL * n * (n + 1) / 2LL;
        ll invalid = total;

        set<pair<int, int>> nonStar;
        nonStar.insert({0, n - 1});
        for (int i = 0; i < n; i++)
        {
            int idx = order[i];

            auto it = nonStar.lower_bound({idx + 1, 0});
            if (it != nonStar.begin())
            {
                --it;
                int l = it->first;
                int r = it->second;
                if (l <= idx && r >= idx)
                {
                    ll temp = r - l + 1;
                    invalid -= temp * (temp + 1) / 2LL;
                    nonStar.erase(it);
                }

                // split into two
                if (l <= idx - 1)
                {
                    ll left = idx - l;
                    invalid += left * (left + 1) / 2LL;
                    nonStar.insert({l, idx - 1});
                }

                if (idx + 1 <= r)
                {
                    ll right = r - idx;
                    invalid += right * (right + 1) / 2;
                    nonStar.insert({idx + 1, r});
                }
            }

            if (total - invalid >= k)
            {
                return i;
            }
        }
        return -1;
    }
};