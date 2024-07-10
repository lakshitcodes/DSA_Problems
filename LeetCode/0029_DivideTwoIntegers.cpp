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
        int dvd = abs(dividend), dvs = abs(divisor);
        int sign = (dividend > 0) ^ (divisor > 0) == 0 ? 1 : -1;
        int result = 0;
        while (dvd >= dvs)
        {
            int temp = dvs, mul = 1;
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