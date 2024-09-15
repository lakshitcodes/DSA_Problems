#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-indices-of-stable-mountains/description/

class Solution
{
public:
    vector<int> stableMountains(vector<int> &height, int threshold)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i - 1] > threshold)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};