#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> freq(k, 0);
        for (auto &i : arr)
        {
            freq[((i % k) + k) % k]++;
        }
        if (freq[0] % 2)
        {
            return false;
        }
        if (k % 2 == 0)
        {
            if (freq[k / 2] % 2)
            {
                return false;
            }
        }
        for (int i = 1; i <= k / 2; i++)
        {
            if (freq[i] != freq[k - i])
            {
                return false;
            }
        }
        return true;
    }
};