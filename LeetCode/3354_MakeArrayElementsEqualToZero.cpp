#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/make-array-elements-equal-to-zero/

class Solution
{
public:
    int countValidSelections(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count = 0;
        int nonZeros = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                nonZeros++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (isValid(nums, nonZeros, i, -1))
                {
                    count++;
                }
                if (isValid(nums, nonZeros, i, 1))
                {
                    count++;
                }
            }
        }

        return count;
    }

private:
    bool isValid(const vector<int> &nums, int nonZeros, int start,
                 int direction)
    {
        int n = nums.size();
        vector<int> temp(nums);
        int curr = start;

        while (nonZeros > 0 && curr >= 0 && curr < n)
        {
            if (temp[curr] > 0)
            {
                temp[curr]--;
                direction *= -1;
                if (temp[curr] == 0)
                {
                    nonZeros--;
                }
            }
            curr += direction;
        }

        return nonZeros == 0;
    }
};