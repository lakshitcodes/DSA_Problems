#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems//sum-of-digits-of-string-after-convert/description/

class Solution
{
public:
    int getLucky(string s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        string num = "";
        for (auto &i : s)
        {
            num += to_string(i - 'a' + 1);
        }
        while (k--)
        {
            int number = 0;
            for (auto &i : num)
            {
                number += i - '0';
            }
            num = to_string(number);
        }
        return stoi(num);
    }
};