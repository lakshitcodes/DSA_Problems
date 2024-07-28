#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-if-digit-game-can-be-won/description/

class Solution
{
public:
    bool canAliceWin(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int singleDigitSum = 0;
        int doubleSum = 0;
        int totalSum = 0;
        for (auto &i : nums)
        {
            totalSum += i;
            if (i / 10 == 0)
            {
                singleDigitSum += i;
            }
            else if (i / 100 == 0)
            {
                doubleSum += i;
            }
        }
        if (singleDigitSum > totalSum - singleDigitSum)
        {
            return true;
        }
        if (doubleSum > totalSum - doubleSum)
        {
            return true;
        }
        return false;
    }
};