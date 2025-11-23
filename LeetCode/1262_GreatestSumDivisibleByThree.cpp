#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/greatest-sum-divisible-by-three/

class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> zero, one, two;
        for (auto &i : nums)
        {
            if (i % 3 == 0)
            {
                zero.push_back(i);
            }
            else if (i % 3 == 1)
            {
                one.push_back(i);
            }
            else
            {
                two.push_back(i);
            }
        }

        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());

        int ans = accumulate(nums.begin(), nums.end(), 0);
        int val = ans % 3;
        int minimum = INT_MAX;
        if (val == 1)
        {
            if (two.size() >= 2)
            {
                minimum = min(minimum, two[0] + two[1]);
            }
            if (one.size())
            {
                minimum = min(minimum, one[0]);
            }
        }
        else if (val == 2)
        {
            if (one.size() >= 2)
            {
                minimum = min(minimum, one[0] + one[1]);
            }
            if (two.size())
            {
                minimum = min(minimum, two[0]);
            }
        }
        else
        {
            minimum = 0;
        }

        return ans - minimum;
    }
};