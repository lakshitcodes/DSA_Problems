#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<int, int> store;
        long long ans = 0;
        for (auto num : nums)
        {
            unordered_map<int, int> temp;
            for (auto &[andVal, count] : store)
            {
                temp[andVal & num] += count;
            }

            temp[num]++;
            // Not Including above to avoid multiple count of the same answer
            for (auto &[andVal, count] : temp)
            {
                if (andVal == k)
                {
                    ans += count;
                }
            }
            store = temp;
        }
        return ans;
    }
};