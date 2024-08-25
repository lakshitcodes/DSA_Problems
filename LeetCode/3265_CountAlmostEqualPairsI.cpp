#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-almost-equal-pairs-i/description/

class Solution
{
public:
    bool isValid(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        if (s1 == s2)
        {
            return true;
        }
        if (s1.size() > s2.size())
        {
            s2 = string(s1.size() - s2.size(), '0') + s2;
        }
        if (s2.size() > s1.size())
        {
            s1 = string(s2.size() - s1.size(), '0') + s1;
        }
        for (int i = 0; i < s1.length(); i++)
        {
            for (int j = i + 1; j < s1.length(); j++)
            {
                swap(s1[i], s1[j]);
                if (s1 == s2)
                {
                    return true;
                }
                swap(s1[i], s1[j]);
            }
        }
        return false;
    }
    int countPairs(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans += isValid(nums[i], nums[j]);
            }
        }
        return ans;
    }
};