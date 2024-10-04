#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = skill.size();
        long long totalSum = accumulate(skill.begin(), skill.end(), 0LL);
        long long reqSum = 2 * totalSum / n;
        unordered_map<int, int> store;
        long long ans = 0;
        for (int i = 0; i < skill.size(); i++)
        {
            if (store.count(reqSum - skill[i]))
            {
                ans += (long long)(reqSum - skill[i]) * skill[i];
                store[reqSum - skill[i]]--;
                if (store[reqSum - skill[i]] == 0)
                {
                    store.erase(reqSum - skill[i]);
                }
            }
            else
            {
                store[skill[i]]++;
            }
        }
        return store.size() == 0 ? ans : -1;
    }
};