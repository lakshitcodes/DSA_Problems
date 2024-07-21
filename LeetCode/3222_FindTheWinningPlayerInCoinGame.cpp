#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-winning-player-in-coin-game/description/

class Solution
{
public:
    string losingPlayer(int x, int y)
    {
        int smallPass = y / 4;
        if (smallPass < x)
        {
            x = smallPass;
        }
        if (x % 2 == 0)
        {
            return "Bob";
        }
        return "Alice";
    }
};