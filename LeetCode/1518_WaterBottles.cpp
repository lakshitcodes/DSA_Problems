#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/water-bottles/description/

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int ans = 0;
        int emptyBottles = 0;
        while (numBottles > 0)
        {
            ans += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
            numBottles += emptyBottles / numExchange;
            emptyBottles %= numExchange;
        }
        return ans;
    }
};