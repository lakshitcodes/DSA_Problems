#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

class Solution
{
public:
    int numberOfWays(string corridor)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 1;
        vector<long long> val;
        for (int i = 0; i < corridor.length(); i++)
        {
            if (corridor[i] == 'S')
            {
                val.push_back(i);
            }
        }
        if (val.size() < 1 || val.size() % 2 != 0)
        {
            return 0;
        }
        const int mod = 1e9 + 7;
        for (int i = 1; i < val.size(); i += 2)
        {
            if (i < val.size() - 1)
            {
                ans = (ans * (val[i + 1] - val[i]) % mod);
            }
        }
        return ans;
    }
};