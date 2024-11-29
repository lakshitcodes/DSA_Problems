#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int m = grid.size();
        int n = grid[0].size();
        
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}}); // time, row(x), col(y)
        
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        visited[0][0] = 1;
        
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            int currTime = curr.first;
            int currRow = curr.second.first;
            int currCol = curr.second.second;
            
            pq.pop();
            
            if (currRow == m - 1 && currCol == n - 1) 
                return currTime;
            
            for (auto move : moves) {
                int nextRow = move.first + currRow;
                int nextCol = move.second + currCol;
                
                if (nextRow >= 0 && nextCol >= 0 && 
                    nextRow < m && nextCol < n && 
                    !visited[nextRow][nextCol]) {
                    
                    int waitTime = ((grid[nextRow][nextCol] - currTime) % 2 == 0) ? 1 : 0;
                    int nextTime = max(currTime + 1, grid[nextRow][nextCol] + waitTime);
                    
                    pq.push({nextTime, {nextRow, nextCol}});
                    visited[nextRow][nextCol] = 1;
                }
            }
        }
        return -1;
    }
};