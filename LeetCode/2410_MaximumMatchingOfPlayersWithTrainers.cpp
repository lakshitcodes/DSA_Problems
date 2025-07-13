#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0;
        int ans = 0;
        while (i < players.size() && j < trainers.size())
        {
            if (players[i] <= trainers[j])
            {
                i++;
                j++;
                ans++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};