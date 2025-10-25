#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/calculate-money-in-leetcode-bank

class Solution
{
public:
    int totalMoney(int n)
    {
        int temp = 28;
        int weeks = n / 7;
        if (weeks > 0)
            temp = weeks * temp + 7 * weeks * (weeks - 1) / 2;
        else
            temp = 0;
        int rem = n % 7;
        temp += rem * (2 * weeks + (rem + 1)) / 2;
        return temp;
    }
};