#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/

class Solution
{
public:
    long long heightReducedByWorker(long long time, long long workerTime)
    {
        long long low = 0, high = 1e5, maxHeight = 0;

        while (low <= high)
        {
            long long mid = (low + high) / 2;
            long long requiredTime = (mid * (mid + 1) / 2) * workerTime;
            if (requiredTime <= time)
            {
                maxHeight = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return maxHeight;
    }

    bool canReduceMountain(long long mountainHeight, vector<int> &workerTimes,
                           long long time)
    {
        long long totalHeight = 0;
        for (int workerTime : workerTimes)
        {
            totalHeight += heightReducedByWorker(time, workerTime);
            if (totalHeight >= mountainHeight)
                return true;
        }
        return totalHeight >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long left = 0, right = 1e18, answer = right;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            if (canReduceMountain(mountainHeight, workerTimes, mid))
            {
                answer = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return answer;
    }
};