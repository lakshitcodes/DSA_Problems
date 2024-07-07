#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

class Solution
{
public:
    int beautySum(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> count(26, 0);
            for (int j = i; j < n; j++)
            {
                count[s[j] - 'a']++;
                int maxVal = 0, minVal = INT_MAX;
                for (auto &c : count)
                {
                    maxVal = max(maxVal, c);
                    if (c != 0)
                        minVal = min(minVal, c);
                }
                ans += maxVal - minVal;
            }
        }
        return ans;
    }
};