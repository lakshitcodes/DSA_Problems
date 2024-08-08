#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/spiral-matrix-iii/

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<vector<int>> ans;
        int counter = 1;
        auto isValid = [&](int x, int y)
        {
            return x >= 0 && y >= 0 && x < rows && y < cols;
        };
        ans.push_back({rStart, cStart});
        while (ans.size() != rows * cols)
        {
            for (int i = 1; i <= counter; i++)
            {
                cStart++;
                if (isValid(rStart, cStart))
                {
                    ans.push_back({rStart, cStart});
                }
            }
            for (int i = 1; i <= counter; i++)
            {
                rStart++;
                if (isValid(rStart, cStart))
                {
                    ans.push_back({rStart, cStart});
                }
            }
            counter++;
            for (int i = 1; i <= counter; i++)
            {
                cStart--;
                if (isValid(rStart, cStart))
                {
                    ans.push_back({rStart, cStart});
                }
            }
            for (int i = 1; i <= counter; i++)
            {
                rStart--;
                if (isValid(rStart, cStart))
                {
                    ans.push_back({rStart, cStart});
                }
            }
            counter++;
        }
        return ans;
    }
};