#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/reordered-power-of-2/

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        set<vector<int>> mp;
        int currVal = 1;
        for (int i = 0; i < 30; i++)
        {
            vector<int> curr(10, 0);
            int temp = currVal;
            while (temp)
            {
                curr[temp % 10]++;
                temp /= 10;
            }
            currVal *= 2;
            mp.insert(curr);
        }
        vector<int> given(10, 0);
        while (n)
        {
            given[n % 10]++;
            n /= 10;
        }
        return mp.count(given);
    }
};