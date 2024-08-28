#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        vector<int> inc(n, 1);
        vector<int> dec(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && inc[j] + 1 > inc[i])
                {
                    inc[i] = inc[j] + 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[j] < nums[i] && dec[j] + 1 > dec[i])
                {
                    dec[i] = dec[j] + 1;
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (dec[i] && inc[i] > 1)
                maxi = max(inc[i] + dec[i], maxi);
        }
        return maxi;
    }
};