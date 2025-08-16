#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-69-number/

class Solution
{
public:
    int maximum69Number(int num)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string s = to_string(num);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '6')
            {
                s[i] = '9';
                return stoi(s);
            }
        }
        return num;
    }
};