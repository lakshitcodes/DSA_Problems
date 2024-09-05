#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-missing-observations/description

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = rolls.size();
        int totalSum = mean * (m + n);
        int mSum = accumulate(rolls.begin(), rolls.end(), 0);
        int nSum = totalSum - mSum;
        if (nSum > n * 6 || nSum < n)
        {
            return {};
        }
        int remainder = nSum % n;
        vector<int> ans(n, nSum / n);
        for (int i = 0; i < remainder; i++)
        {
            ans[i] += 1;
        }
        return ans;
    }
};