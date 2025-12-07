#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution
{
public:
    int countOdds(int low, int high)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = (high - low) / 2;
        if (low % 2 || high % 2)
        {
            return n + 1;
        }
        return n;
    }
};