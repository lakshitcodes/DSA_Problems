#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/palindrome-number/description/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        int n = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != s[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};