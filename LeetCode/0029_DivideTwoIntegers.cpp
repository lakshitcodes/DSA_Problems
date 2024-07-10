#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/divide-two-integers/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        long long dvd = labs(dividend), dvs = labs(divisor);
        int sign = (dividend > 0) ^ (divisor > 0) == 0 ? 1 : -1;
        long long result = 0;
        while (dvd >= dvs)
        {
            long long temp = dvs, mul = 1;
            while (temp << 1 <= dvd)
            {
                temp <<= 1;
                mul <<= 1;
            }
            dvd -= temp;
            result += mul;
        }
        return result * sign;
    }
};