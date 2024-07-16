#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

class Solution
{
public:
    int totalFruits(int N, vector<int> &fruits)
    {
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int ans = 0;
        while (r < N)
        {
            mp[fruits[r]]++;
            if (mp.size() <= 2)
            {
                ans = max(ans, r - l + 1);
            }
            else
            {
                while (mp.size() > 2)
                {
                    mp[fruits[l]]--;
                    if (mp[fruits[l]] == 0)
                    {
                        mp.erase(fruits[l]);
                    }
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};