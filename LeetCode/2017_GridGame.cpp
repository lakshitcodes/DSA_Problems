#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/grid-game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long min_result = LLONG_MAX;  // Start with a large number for the minimum score.
        long long row1_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);  // Top row sum
        long long row2_sum = 0;  // Bottom row sum starts at 0.

        for (int i = 0; i < grid[0].size(); ++i) {
            // the main intuition here is that whenever the robot 1 changes direction
            // Then robot 2 has only 2 choices to collect the coins
            // The section of row 2 upto the current cell or the section in the first row to the right of where it changes direction
            // Thus returning the maximum of it
            // Visualising this
            // 1 is the path of the robot 1, and 0 are the leftover choices
            // 1 1 1 1 1 0 0 0 0 0 0 0
            // 0 0 0 0 1 1 1 1 1 1 1 1
            // robot 2 can choose either of the 0 sections

            
            row1_sum -= grid[0][i];  // Move the top player forward, subtract current value.
            min_result = min(min_result, max(row1_sum, row2_sum));  // Update the minimum of the max scores.
            row2_sum += grid[1][i];  // Move the bottom player forward, add current value.
        }

        return min_result;  // Return the minimum maximum score.
    }
};