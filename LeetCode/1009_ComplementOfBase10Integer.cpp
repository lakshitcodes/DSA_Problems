#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/complement-of-base-10-integer/description/

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (n == 0)
        {
            return 1;
        }
        int value = log2(n) + 1;
        long long mask = 1 << value;
        mask--;
        return n ^ mask;
    }
};