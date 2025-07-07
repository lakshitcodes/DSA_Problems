#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    }
    int maxEvents(vector<vector<int>> &events)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(events.begin(), events.end(), comp);
        vector<int> occupied(1e5 + 1, 0);
        int ans = 0;
        for (int i = 0; i < events.size(); i++)
        {
            int idx = events[i][1];
            while (idx >= events[i][0] && occupied[idx])
            {
                idx--;
            }
            if (idx >= events[i][0])
            {
                occupied[idx] = 1;
                ans++;
            }
        }
        return ans;
    }
};