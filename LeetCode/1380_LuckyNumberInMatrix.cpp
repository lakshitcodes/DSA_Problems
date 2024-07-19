#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lucky-numbers-in-a-matrix/description

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> minRow;
        for (int i = 0; i < matrix.size(); i++)
        {
            int minElement = matrix[i][0];
            for (int j = 1; j < matrix[0].size(); j++)
            {
                minElement = min(minElement, matrix[i][j]);
            }
            minRow.push_back(minElement);
        }
        vector<int> maxCol;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            int maxElement = matrix[0][i];
            for (int j = 1; j < matrix.size(); j++)
            {
                maxElement = max(maxElement, matrix[j][i]);
            }
            maxCol.push_back(maxElement);
        }
        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j])
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};