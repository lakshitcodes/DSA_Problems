#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/

class Solution
{
public:
    int countPermutations(vector<int> &complexity)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = complexity.size();
        const int mod = 1e9 + 7;

        long long ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (complexity[i] <= complexity[0])
            {
                return 0;
            }
            ans *= i;
            ans %= mod;
        }

        return ans;
    }
};