#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/subarrays-with-k-different-integers/description/

class Solution
{
private:
    int atMostK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        int n = nums.size();
        int ans = 0;
        while (right < n)
        {
            mp[nums[right]]++;
            while (mp.size() > k)
            {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0)
                {
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};