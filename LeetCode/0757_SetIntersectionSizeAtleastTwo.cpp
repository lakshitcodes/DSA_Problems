#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/set-intersection-size-at-least-two/description/

class Solution
{
public:
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(intervals.begin(), intervals.end(), comparator);
        vector<int> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (ans.empty() || ans.back() < intervals[i][0])
            {
                ans.push_back(intervals[i][1] - 1);
                ans.push_back(intervals[i][1]);
            }
            else if (ans.back() == intervals[i][0])
            {
                ans.push_back(intervals[i][1]);
            }
            else if (intervals[i][0] > ans[ans.size() - 2])
            {
                ans.push_back(intervals[i][1]);
            }
        }
        return ans.size();
    }
};