#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (k == 0)
        {
            return 0;
        }
        if (k == cardPoints.size())
        {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }
        int lSum = 0;
        for (int i = 0; i < k; i++)
        {
            lSum += cardPoints[i];
        }
        int rSum = 0;
        int ans = lSum;
        for (int i = k - 1; i >= 0; i--)
        {
            lSum -= cardPoints[i];
            rSum += cardPoints[cardPoints.size() + i - k];
            ans = max(ans, lSum + rSum);
        }
        return ans;
    }
};