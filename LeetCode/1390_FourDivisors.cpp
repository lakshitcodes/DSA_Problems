#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/four-divisors/

class Solution
{
public:
    int sum(int val)
    {
        int count = 0;
        int total = 0;
        for (int i = 1; i * i <= val; i++)
        {
            if (val % i == 0)
            {
                int second = val / i;
                if (second != i)
                {
                    count += 2;
                    total += second + i;
                }
                else
                {
                    count += 1;
                    total += i;
                }
            }
        }
        if (count == 4)
        {
            return total;
        }
        return 0;
    }
    int sumFourDivisors(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += sum(nums[i]);
        }
        return ans;
    }
};