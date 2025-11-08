#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        if (n == 0)
            return 0; // base case
        int numOp = 0, k;
        int sgn = 1;
        for (; n > 0; n ^= (1 << k), sgn *= -1)
        {
            k = 31 - __builtin_clz(n);
            numOp += sgn * ((1 << (k + 1)) - 1);
        }
        return numOp;
    }
};