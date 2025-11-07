#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximise-the-minimum-powered-city

class Solution
{
public:
    bool isGood(vector<int> &stations, int r, long long minPower, int additional)
    {
        int n = stations.size();

        long long windowPower = accumulate(stations.begin(), stations.begin() + r, 0ll);
        vector<int> additions(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i + r < n)
            {
                windowPower += stations[i + r];
            }
            if (windowPower < minPower)
            {
                long long needed = minPower - windowPower;
                if (needed > additional)
                {
                    return false;
                }

                additions[min(n - 1, i + r)] += needed;
                additional -= needed;
                windowPower = minPower;
            }
            if (i - r >= 0)
            {
                windowPower -= stations[i - r] + additions[i - r];
            }
        }
        return true;
    }
    long long maxPower(vector<int> &stations, int r, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long left = 0;
        long long right = accumulate(stations.begin(), stations.end(), 0ll) + k;
        long long ans = 0;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            if (isGood(stations, r, mid, k))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};