#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/rotate-string/

class Solution
{
public:
    bool rotateCheck(string s, string goal, int rotation)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[(i + rotation) % goal.length()])
            {
                return false;
            }
        }
        return true;
    }
    bool rotateString(string s, string goal)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (s.length() != goal.length())
        {
            return false;
        }
        if (s.length() == 0)
        {
            return true;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (rotateCheck(s, goal, i))
            {
                return true;
            }
        }
        return false;
    }
};