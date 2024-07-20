#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int rows = rowSum.size();
        int cols = colSum.size();
        int curRow = 0, curCol = 0;
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        while (curRow < rows || curCol < cols)
        {
            if (curRow >= rows)
            {
                ans[rows - 1][curCol] = colSum[curCol];
                curCol++;
                continue;
            }
            else if (curCol >= cols)
            {
                ans[curRow][cols - 1] = rowSum[curRow];
                curRow++;
                continue;
            }

            int currValue = min(rowSum[curRow], colSum[curCol]);
            rowSum[curRow] -= currValue;
            colSum[curCol] -= currValue;
            ans[curRow][curCol] = currValue;
            if (rowSum[curRow] == 0)
            {
                curRow++;
            }
            if (colSum[curCol] == 0)
            {
                curCol++;
            }
        }
        return ans;
    }
};