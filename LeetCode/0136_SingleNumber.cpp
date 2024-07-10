#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/single-number/description/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto i : nums)
        {
            ans ^= i;
        }
        return ans;
    }
};