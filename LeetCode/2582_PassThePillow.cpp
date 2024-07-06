#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/pass-the-pillow/

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int timeToEnd = n - 1;
        time %= (2 * timeToEnd);
        int turn = time / timeToEnd;
        time %= timeToEnd;
        if (turn)
        {
            return n - time;
        }
        return 1 + time;
    }
};