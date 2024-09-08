#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/

class Solution
{
public:
    bool canAchieveScore(vector<int> &start, int d, int x)
    {
        int n = start.size();
        long long prev_chosen = start[0];
        for (long long i = 1; i < n; ++i)
        {
            long long next_possible = max(prev_chosen + x, (long long)start[i]);
            if (next_possible > start[i] + d)
            {
                return false;
            }
            prev_chosen = next_possible;
        }
        return true;
    }

    int maxPossibleScore(vector<int> &start, int d)
    {
        long long n = start.size();
        sort(start.begin(), start.end());
        long long low = 0, high = start[n - 1] + d, best = 0;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (canAchieveScore(start, d, mid))
            {
                best = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return best;
    }
};