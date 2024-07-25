#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/sort-an-array/description/

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(), nums.end());
        return nums;
    }
};