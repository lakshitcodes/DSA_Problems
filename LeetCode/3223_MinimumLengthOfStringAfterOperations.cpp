#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-length-of-string-after-operations/description/

class Solution
{
public:
    int minimumLength(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> count(26, 0);
        for (auto &i : s)
        {
            count[i - 'a']++;
        }
        int ans = 0;
        for (auto &i : count)
        {
            while (i >= 3)
            {
                i -= 2;
            }
            ans += i;
        }
        return ans;
    }
};