#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/hand-of-straights/description/

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize)
        {
            return false;
        }
        sort(hand.begin(), hand.end());
        unordered_map<int, int> mp;
        for (auto i : hand)
        {
            mp[i]++;
        }
        for (int i = 0; i < hand.size(); i++)
        {
            if (mp[hand[i]])
            {
                mp[hand[i]]--;
                for (int j = 1; j < groupSize; j++)
                {
                    if (mp[hand[i] + j])
                    {
                        mp[hand[i] + j]--;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};