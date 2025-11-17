#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count = k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                count++;
            }
            else
            {
                if (count < k)
                {
                    return false;
                }
                count = 0;
            }
        }
        return true;
    }
};