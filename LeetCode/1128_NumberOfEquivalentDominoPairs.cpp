#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = dominoes.size();
        for (int i = 0; i < n; i++)
        {
            sort(dominoes[i].begin(), dominoes[i].end());
        }
        unordered_map<string, int> mp;
        int ans = 0;
        for (auto &i : dominoes)
        {
            string key = to_string(i[0]) + "00000" + to_string(i[1]);
            if (mp.count(key))
            {
                ans += mp[key];
            }
            mp[key]++;
        }
        return ans;
    }
};