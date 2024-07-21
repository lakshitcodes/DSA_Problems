#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/description/

class Solution
{
public:
    int minChanges(int n, int k)
    {
        int countOnesN = __builtin_popcount(n);
        int countOnesK = __builtin_popcount(k);

        // If k has more 1 bits than n, it's impossible to convert n to k
        if (countOnesK > countOnesN)
            return -1;

        int count = 0;
        while (n > 0 || k > 0)
        {
            int left = n & 1;
            int right = k & 1;
            n >>= 1;
            k >>= 1;

            if (left == 0 && right == 1)
            {
                return -1;
            }
            // Count the number of differing bits
            if (left != right)
            {
                count++;
            }
        }
        return count;
    }
};