#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/

class Solution
{
public:
    string getSmallestString(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = s.length();

        for (int i = 0; i < n - 1; i++)
        {
            if ((s[i] - '0') % 2 == (s[i + 1] - '0') % 2)
            {

                if (s[i] > s[i + 1])
                {
                    swap(s[i], s[i + 1]);
                    return s;
                }
            }
        }

        return s;
    }
};