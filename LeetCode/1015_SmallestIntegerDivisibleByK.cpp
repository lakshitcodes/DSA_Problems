#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-integer-divisible-by-k/

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (k == 1)
        {
            return 1;
        }
        if (k % 2 == 0 || k % 5 == 0)
        {
            return -1;
        }
        unordered_set<int> rem;
        int len = 1;
        int prev = 1;
        while (true)
        {
            int val = prev;
            int newRem = ((val * 10) % k + 1) % k;
            if (rem.count(newRem))
            {
                return -1;
            }
            rem.insert(newRem);
            len++;
            prev = newRem;
            if (newRem == 0)
            {
                return len;
            }
        }
        return -1;
    }
};