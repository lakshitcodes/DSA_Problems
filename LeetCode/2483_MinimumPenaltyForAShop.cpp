#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-penalty-for-a-shop/

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int y = 0, n = 0;
        for (int i = 0; i < customers.length(); i++)
        {
            if (customers[i] == 'Y')
            {
                y++;
            }
        }
        int minPenalty = y;
        int idx = 0;
        for (int i = 0; i < customers.length(); i++)
        {
            if (customers[i] == 'Y')
            {
                y--;
            }
            else
            {
                n++;
            }
            int currPenalty = n + y;
            if (currPenalty < minPenalty)
            {
                minPenalty = currPenalty;
                idx = i + 1;
            }
        }
        return idx;
    }
};