#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/fruits-into-baskets/

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, int> mp;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < fruits.size(); r++)
        {
            mp[fruits[r]]++;
            if (mp.size() <= 2)
            {
                ans = max(ans, r - l + 1);
            }
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
        return ans;
    }
};