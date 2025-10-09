#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/

class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = skill.size(), m = mana.size();

        vector<long long> done(n + 1, 0);

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                done[i + 1] = max(done[i + 1], done[i]) + 1LL * mana[j] * skill[i];
            }
            for (int i = n - 1; i > 0; i--)
            {
                done[i] = done[i + 1] - 1ll * mana[j] * skill[i];
            }
        }
        return done[n];
    }
};