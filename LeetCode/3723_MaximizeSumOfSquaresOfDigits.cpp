#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximize-sum-of-squares-of-digits/

class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (sum > num * 9)
        {
            return "";
        }
        string ans = "";
        for (int i = 0; i < num; i++)
        {
            ans += to_string(min(9, sum));
            sum = max(sum - 9, 0);
        }
        return ans;
    }
};