#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<int, int> st;
        for (auto &i : nums)
        {
            int val = (i % value + value) % value;
            st[val]++;
        }
        for (int i = 0; i < 1e5 + 5; i++)
        {
            if (st.count(i % value) && st[i % value] > 0)
            {
                st[i % value]--;
                continue;
            }
            return i;
        }
        return -1;
    }
};