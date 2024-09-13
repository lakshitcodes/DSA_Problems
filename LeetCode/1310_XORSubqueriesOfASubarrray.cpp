#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = arr.size();
        vector<int> prefix(n, 0);
        int totalXor = 0;
        for (int i = 0; i < n; i++)
        {
            totalXor ^= arr[i];
            prefix[i] = totalXor;
        }
        vector<int> ans;
        for (auto &i : queries)
        {
            int currAns = prefix[i[1]];
            if (i[0] > 0)
            {
                currAns ^= prefix[i[0] - 1];
            }
            ans.push_back(currAns);
        }
        return ans;
    }
};