#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/next-greater-element-i/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> store;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums2[st.top()] <= nums2[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                store[nums2[i]] = nums2[st.top()];
            }
            st.push(i);
        }
        vector<int> ans;
        for (auto i : nums1)
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