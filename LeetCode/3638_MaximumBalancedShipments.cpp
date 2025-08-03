#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-balanced-shipments/

class Solution
{
public:
    int maxBalancedShipments(vector<int> &weight)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        int currMaxi = weight[0];
        for (int i = 1; i < weight.size(); i++)
        {
            if (weight[i] < currMaxi)
            {
                ans++;
                if (i < weight.size() - 1)
                {
                    currMaxi = weight[++i];
                }
            }
            else
            {
                currMaxi = max(currMaxi, weight[i]);
            }
        }
        return ans;
    }
};