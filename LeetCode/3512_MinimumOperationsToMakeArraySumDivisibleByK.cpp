#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int sum = accumulate(nums.begin(), nums.end(), k);
        return sum % k;
    }
};