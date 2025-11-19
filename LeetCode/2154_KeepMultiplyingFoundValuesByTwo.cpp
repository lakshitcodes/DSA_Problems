#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/keep-multiplying-found-values-by-two/

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<int> val(nums.begin(), nums.end());
        while (true)
        {
            if (val.count(original))
            {
                original *= 2;
                continue;
            }
            return original;
        }
        return 0;
    }
};