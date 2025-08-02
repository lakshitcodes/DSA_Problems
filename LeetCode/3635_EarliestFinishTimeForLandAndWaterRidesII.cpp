#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides--ii/

class Solution
{
public:
    struct Ride
    {
        long long start;
        long long duration;
        long long finish;
    };

    static bool byFinish(const Ride &a, const Ride &b)
    {
        return a.finish < b.finish;
    }

    static bool byStart(const Ride &a, const Ride &b)
    {
        return a.start < b.start;
    }

    long long calculateOneDirection(vector<Ride> &rides1, vector<Ride> &rides2)
    {
        if (rides1.empty() || rides2.empty())
        {
            return LLONG_MAX;
        }

        sort(rides1.begin(), rides1.end(), byFinish);
        sort(rides2.begin(), rides2.end(), byStart);

        int n2 = rides2.size();

        vector<long long> minFinish(n2 + 1, LLONG_MAX);
        for (int j = n2 - 1; j >= 0; --j)
        {
            minFinish[j] = min(rides2[j].finish, minFinish[j + 1]);
        }

        long long allMinFinish = LLONG_MAX;
        long long minDuration = LLONG_MAX;
        int j = 0;

        for (const auto &ride1 : rides1)
        {
            long long finish1 = ride1.finish;

            while (j < n2 && rides2[j].start <= finish1)
            {
                minDuration = min(minDuration, rides2[j].duration);
                j++;
            }

            if (minDuration != LLONG_MAX)
            {
                allMinFinish = min(allMinFinish, finish1 + minDuration);
            }

            if (j < n2)
            {
                allMinFinish = min(allMinFinish, minFinish[j]);
            }
        }
        return allMinFinish;
    }

    long long earliestFinishTime(const vector<int> &landStartTime, const vector<int> &landDuration,
                                 const vector<int> &waterStartTime, const vector<int> &waterDuration)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<Ride> landRides;
        for (size_t i = 0; i < landStartTime.size(); ++i)
        {
            landRides.push_back({(long long)landStartTime[i],
                                 (long long)landDuration[i],
                                 (long long)landStartTime[i] + landDuration[i]});
        }

        vector<Ride> waterRides;
        for (size_t i = 0; i < waterStartTime.size(); ++i)
        {
            waterRides.push_back({(long long)waterStartTime[i],
                                  (long long)waterDuration[i],
                                  (long long)waterStartTime[i] + waterDuration[i]});
        }

        long long a = calculateOneDirection(landRides, waterRides);
        long long b = calculateOneDirection(waterRides, landRides);

        return min(a, b);
    }
};
