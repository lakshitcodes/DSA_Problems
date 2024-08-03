#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return arr == target;
    }
};