#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/snake-in-matrix/description/

class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &commands)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int i = 0, j = 0;
        for (auto &c : commands)
        {
            if (c == "RIGHT")
            {
                j++;
            }
            if (c == "LEFT")
            {
                j--;
            }
            if (c == "UP")
            {
                i--;
            }
            if (c == "DOWN")
            {
                i++;
            }
        }
        return i * n + j;
    }
};