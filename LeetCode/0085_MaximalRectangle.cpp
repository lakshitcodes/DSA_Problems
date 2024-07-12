#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximal-rectangle/

class Solution
{
public:
    vector<int> nextSmallerindex(vector<int> &arr, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerindex(vector<int> &arr, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerindex(heights, n);
        vector<int> prev(n);
        int ans = 0;
        prev = prevSmallerindex(heights, n);
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            ans = max(ans, l * b);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        vector<int> height(matrix[0].size(), 0);
        int maxi = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < height.size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    height[j]++;
                }
                else
                {
                    height[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(height));
        }
        return maxi;
    }
};