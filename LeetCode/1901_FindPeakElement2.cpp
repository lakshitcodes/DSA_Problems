#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-a-peak-element-ii/description/

// First Approach is Pretty Easy, use 2 nested loops to traverse and check for each and every element.

// Second Approach is to use Binary Search, we can use Binary Search to find the peak element in a row.
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int maxRow = 0;
            int midCol = (low + high) >> 1;
            for (int i = 0; i < n; i++)
            {
                if (mat[i][midCol] > mat[maxRow][midCol])
                {
                    maxRow = i;
                }
            }

            int currElement = mat[maxRow][midCol];
            int leftElement = midCol == 0 ? -1 : mat[maxRow][midCol - 1];
            int rightElement = midCol == m - 1 ? -1 : mat[maxRow][midCol + 1];
            if (currElement > leftElement && currElement > rightElement)
            {
                return {maxRow, midCol};
            }
            if (currElement < leftElement)
            {
                high = midCol - 1;
            }
            else
            {
                low = midCol + 1;
            }
        }
        return {-1, -1};
    }
};