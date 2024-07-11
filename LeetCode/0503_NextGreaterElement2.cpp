#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/next-greater-element-ii/

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<int, int> store;
        int n = nums.size();
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top() % n] <= nums[i % n])
            {
                st.pop();
            }
            if (!st.empty() && i < n)
            {
                store[i] = nums[st.top()];
            }
            st.push(i % n);
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (store.find(i) != store.end())
            {
                ans.push_back(store[i]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};