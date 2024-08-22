#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-complement/description/

class Solution
{
public:
    int findComplement(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int value = log2(n) + 1;
        long long mask = 1 << value;
        mask--;
        return n ^ mask;
    }
};