#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution
{
public:
    class comparator
    {
    public:
        static bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        }
    };
    vector<int> frequencySort(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        unordered_map<int, int> hashMap;
        for (auto i : nums)
        {
            hashMap[i]++;
        }
        for (auto &i : hashMap)
        {
            pq.push({i.second, i.first});
        }
        vector<int> ans;
        while (!pq.empty())
        {
            auto frontElement = pq.top();
            pq.pop();
            for (int i = 0; i < frontElement.first; i++)
            {
                ans.push_back(frontElement.second);
            }
        }
        return ans;
    }
};