#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix[0].size();
        int n = matrix.size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};