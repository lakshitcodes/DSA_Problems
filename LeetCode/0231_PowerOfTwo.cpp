#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/power-of-two/

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (n < 1)
        {
            return false;
        }
        int p = log2(n);
        int tempN = 1 << p;
        return tempN == n;
    }
};