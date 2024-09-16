#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-time-difference/

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> minutes;
        for (auto &time : timePoints)
        {
            int hours = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            minutes.push_back(hours * 60 + minute);
            cout << minutes.back() << endl;
        }
        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++)
        {
            minDiff = min({minDiff, minutes[i] - minutes[i - 1], abs(24 * 60 - minutes[i] + minutes[i - 1])});
        }
        minDiff = minDiff = min({minDiff, abs(minutes[0] - minutes.back()), abs(24 * 60 - minutes.back() + minutes[0])});
        return minDiff;
    }
};