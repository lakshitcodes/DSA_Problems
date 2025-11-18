#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/1-bit-and-2-bit-characters/

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = bits.size();
        int i = 0;
        while (i < n - 1)
            i += bits[i] + 1;

        return i == n - 1;
    }
};