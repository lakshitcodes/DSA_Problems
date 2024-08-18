#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/description/

class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int count0 = 0;
            int count1 = 0;
            for (int j = i; j < s.length(); j++)
            {
                if (s[j] == '1')
                {
                    count1++;
                }
                if (s[j] == '0')
                {
                    count0++;
                }
                if (count1 <= k || count0 <= k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};