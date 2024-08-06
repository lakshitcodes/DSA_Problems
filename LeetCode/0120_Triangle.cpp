#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/triangle/description/

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = triangle.size();
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};