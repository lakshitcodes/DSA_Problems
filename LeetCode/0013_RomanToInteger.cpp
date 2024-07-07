#include<bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/roman-to-integer/description/

class Solution
{
public:
    int romanToInt(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<char, int> values;
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;

        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (values[s[i]] < values[s[i + 1]])
            {
                ans -= values[s[i]];
            }
            else
            {
                ans += values[s[i]];
            }
        }
        return ans;
    }
};