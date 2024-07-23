#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    class compare
    {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        for (auto i : nums)
        {
            count[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (auto i : count)
        {
            if (i.second)
            {
                pq.push({i.first, i.second});
            }
        }
        vector<int> ans;
        while (k)
        {
            k--;
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};