#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto s : arr)
        {
            for (auto n : s)
            {
                pq.push(n);
            }
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};