#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-key-of-the-numbers/

class Solution
{
public:
    int generateKey(int num1, int num2, int num3)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string s3 = to_string(num3);
        if (s1.length() < 4)
        {
            string temp = string(4 - s1.length(), '0');
            s1 = temp + s1;
        }
        if (s2.length() < 4)
        {
            string temp = string(4 - s2.length(), '0');
            s2 = temp + s2;
        }
        if (s3.length() < 4)
        {
            string temp = string(4 - s3.length(), '0');
            s3 = temp + s3;
        }
        string key = "";
        for (int i = 0; i < 4; i++)
        {
            char min_digit = std::min({s1[i], s2[i], s3[i]});
            key += min_digit;
        }

        return stoi(key);
    }
};