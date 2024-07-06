#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    string frequencySort(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<char, int> freq;
        for (auto &c : s)
        {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto i : freq)
        {
            pq.push({i.second, i.first});
        }
        string ans = "";
        while (!pq.empty())
        {
            ans += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return ans;
    }
};