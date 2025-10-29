#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-number-with-all-set-bits/

class Solution
{
public:
    int smallestNumber(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int power = log2(n);

        return pow(2, power + 1) - 1;
    }
};