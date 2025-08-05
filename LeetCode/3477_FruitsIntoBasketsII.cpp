#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/fruits-into-baskets-ii/

class Solution
{
public:
    bool canPlace(int fruit, vector<int> &baskets)
    {
        for (auto &i : baskets)
        {
            if (i >= fruit)
            {
                i = 0;
                return true;
            }
        }
        return false;
    }
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!canPlace(fruits[i], baskets))
            {
                ans++;
            }
        }

        return ans;
    }
};