#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int a = -1, b = -1, c = -1;
        long long ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')
            {
                a = i;
            }
            if (s[i] == 'b')
            {
                b = i;
            }
            if (s[i] == 'c')
            {
                c = i;
            }
            if (a != -1 && b != -1 && c != -1)
            {
                ans += min({a, b, c}) + 1;
            }
        }
        return ans;
    }
};