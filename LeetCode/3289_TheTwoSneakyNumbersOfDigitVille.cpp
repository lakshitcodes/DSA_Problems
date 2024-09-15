#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems//the-two-sneaky-numbers-of-digitville/

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<int> store;
        vector<int> ans;
        for (auto &i : nums)
        {
            if (store.count(i))
            {
                ans.push_back(i);
            }
            store.insert(i);
        }
        return ans;
    }
};