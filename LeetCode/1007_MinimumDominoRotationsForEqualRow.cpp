#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int a = tops[0];
        int b = bottoms[0];
        int p = 0, q = 0, r = 0, s = 0;
        for (int i = 0; i < tops.size(); i++)
        {
            // Making top = a
            if (tops[i] != a)
            {
                if (bottoms[i] == a)
                {
                    p++;
                }
                else
                {
                    p = INT_MIN;
                }
            }
            // Making top = b
            if (tops[i] != b)
            {
                if (bottoms[i] == b)
                {
                    q++;
                }
                else
                {
                    q = INT_MIN;
                }
            }
            // Making bottom = a
            if (bottoms[i] != a)
            {
                if (tops[i] == a)
                {
                    r++;
                }
                else
                {
                    r = INT_MIN;
                }
            }
            // Making bottom = b
            if (bottoms[i] != b)
            {
                if (tops[i] == b)
                {
                    s++;
                }
                else
                {
                    s = INT_MIN;
                }
            }
        }
        if (p < 0 && q < 0 && r < 0 && s < 0)
        {
            return -1;
        }
        if (p < 0)
        {
            p = INT_MAX;
        }
        if (q < 0)
        {
            q = INT_MAX;
        }
        if (r < 0)
        {
            r = INT_MAX;
        }
        if (s < 0)
        {
            s = INT_MAX;
        }
        return min({p, q, r, s});
    }
};