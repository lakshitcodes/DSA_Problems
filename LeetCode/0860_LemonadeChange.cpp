#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lemonade-change/

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        // Store the count of notes
        vector<int> count(3, 0);
        for (auto &bill : bills)
        {
            if (bill == 5)
            {
                count[0]++;
            }
            else if (bill == 10)
            {
                if (count[0] == 0)
                {
                    return false;
                }
                count[0]--;
                count[1]++;
            }
            else
            {
                if (count[1] == 0 && count[0] < 3)
                {
                    return false;
                }
                if (count[0] == 0)
                {
                    return false;
                }
                if (count[1] == 0)
                {
                    count[0] -= 3;
                    count[2]++;
                }
                else
                {
                    count[1]--;
                    count[0]--;
                    count[2]++;
                }
            }
        }
        return true;
    }
};