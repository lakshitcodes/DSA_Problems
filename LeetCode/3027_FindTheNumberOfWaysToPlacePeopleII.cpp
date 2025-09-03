#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii

class Solution
{
public:
    static bool cmp(const vector<int> &p, const vector<int> &q)
    {
        return (p[0] == q[0]) ? p[1] < q[1] : p[0] > q[0]; // order by (x, >)
    }
    int numberOfPairs(vector<vector<int>> &points)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(points.begin(), points.end(), cmp);
        int n = points.size(), ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int y = INT_MAX, yi = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                const int yj = points[j][1];
                if (yj >= yi && y > yj)
                { // points[j] cannot be in between
                    ans++;
                    y = yj;
                    if (yi == yj)
                        break;
                }
            }
        }
        return ans;
    }
};