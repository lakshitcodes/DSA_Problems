#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/

class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int minFinishTime = INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                // land  water
                int a = landStartTime[i];
                int b = a + landDuration[i];
                int sW = max(b, waterStartTime[j]);
                int fW = sW + waterDuration[j];
                minFinishTime = min(minFinishTime, fW);

                // water  land
                sW = waterStartTime[j];
                fW = sW + waterDuration[j];
                int a2 = max(fW, landStartTime[i]);
                int b2 = a2 + landDuration[i];
                minFinishTime = min(minFinishTime, b2);
            }
        }
        return minFinishTime;
    }
};