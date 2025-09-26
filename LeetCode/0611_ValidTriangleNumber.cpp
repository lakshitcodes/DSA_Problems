#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/valid-triangle-number

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int right = nums.size() - 1; right >= 0; right--)
        {
            int left = 0;
            int mid = right - 1;
            while (left < mid)
            {
                if (nums[left] + nums[mid] > nums[right])
                {
                    ans += mid - left;
                    mid--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ans;
    }
};