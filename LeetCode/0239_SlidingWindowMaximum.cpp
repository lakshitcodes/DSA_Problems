#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sliding-window-maximum/

//--------------Brute Force----------------------
class Solution
{
public:
    int maxElement(int i, int j, vector<int> &nums)
    {
        int maxEle = nums[i];
        for (; i < j; i++)
        {
            maxEle = max(maxEle, nums[i]);
        }
        return maxEle;
    }
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> ans;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            ans.push_back(maxElement(i, i + k, nums));
        }
        return ans;
    }
};
// This gives TLE

//--------------Optimal Approach----------------------
// Here Deque is used , now whenever we check for a new window, we check if the front element is out of bonds , then if we pop it
// then we check if the back element is smaller than the current element then we pop it continously to remove the last element so that the front of the deque has elements in increasing order , then we push the current element
// then we check if the window size is reached then we push the front element of the deque to the answer vector
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (!dq.empty() && i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};