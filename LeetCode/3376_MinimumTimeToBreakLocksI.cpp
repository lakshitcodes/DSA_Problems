#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-time-to-break-locks-i/

class Solution {
public:
    int calculateTime(vector<int>& order, int K) {
        int totalTime = 0;
        int X = 1;

        for (int s : order) {
            int time = (s + X - 1) / X;
            totalTime += time;
            X += K;
        }

        return totalTime;
    }
    int findMinimumTime(vector<int>& strength, int K) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = strength.size();
        int minTime = INT_MAX;

        sort(strength.begin(), strength.end());
        do {
            int currentTime = calculateTime(strength, K);
            minTime = min(minTime, currentTime);
        } while (next_permutation(strength.begin(), strength.end()));

        return minTime;
    }
};