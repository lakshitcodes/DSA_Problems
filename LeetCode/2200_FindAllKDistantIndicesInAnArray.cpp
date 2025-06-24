#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        set<int> indexes;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == key)
            {
                int lo = max(0, i - k);
                int hi = min((int)nums.size() - 1, i + k);
                for (int j = lo; j <= hi; j++)
                {
                    indexes.insert(j);
                }
            }
        }
        return vector<int>(indexes.begin(), indexes.end());
    }
};