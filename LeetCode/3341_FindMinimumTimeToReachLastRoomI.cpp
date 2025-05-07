#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});
        moveTime[0][0] = INT_MAX;
        while (!pq.empty())
        {
            vector<int> front = pq.top();
            pq.pop();
            int val = front[0];
            int x = front[1];
            int y = front[2];
            if (x == m - 1 && y == n - 1)
            {
                return val;
            }
            for (auto &[dx, dy] : dir)
            {
                int nX = dx + x;
                int nY = dy + y;
                if (nX >= 0 && nX < m && nY >= 0 && nY < n && moveTime[nX][nY] != INT_MAX)
                {
                    pq.push({max(moveTime[nX][nY], val) + 1, nX, nY});
                    moveTime[nX][nY] = INT_MAX;
                }
            }
        }
        return 0;
    }
};