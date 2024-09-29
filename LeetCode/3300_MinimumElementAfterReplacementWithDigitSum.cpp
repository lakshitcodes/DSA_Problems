#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/

class Solution
{
public:
    int minElement(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int currNum = nums[i];
            int newNum = 0;
            while (currNum > 0)
            {
                newNum += currNum % 10;
                currNum /= 10;
            }
            ans = min(ans, newNum);
        }
        return ans;
    }
};