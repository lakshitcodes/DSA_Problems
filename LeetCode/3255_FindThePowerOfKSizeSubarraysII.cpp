#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/description/

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (k == 1)
            return nums;

        int r = 0, l = 1;
        vector<int> ans;
        int wrong = 0;
        // Initial
        while (l < k)
        {
            if (nums[l] != nums[l - 1] + 1)
            {
                if (ans.size() == 0)
                    ans.push_back(-1);
                wrong++;
            }
            l++;
        }
        if (ans.size() == 0)
        {
            ans.push_back(nums[k - 1]);
        }
        // For the rest
        while (l < nums.size())
        {
            r++;
            if (nums[r] != nums[r - 1] + 1)
            {
                wrong--;
            }

            if ((nums[l] == nums[l - 1] + 1) && wrong <= 0)
            {
                ans.push_back(nums[l]);
            }
            else
            {
                ans.push_back(-1);
            }

            if (nums[l] != nums[l - 1] + 1)
                wrong++;

            l++;
        }

        return ans;
    }
};