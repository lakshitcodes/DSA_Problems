#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int maxArea = 0;
        int maxLen = 0;
        for (int i = 0; i < dimensions.size(); i++)
        {
            int len = dimensions[i][0];
            int bred = dimensions[i][1];

            int currDiag = len * len + bred * bred;
            if (currDiag > maxLen)
            {
                maxLen = currDiag;
                maxArea = len * bred;
            }
            else if (currDiag == maxLen)
            {
                maxArea = max(maxArea, len * bred);
            }
        }
        return maxArea;
    }
};