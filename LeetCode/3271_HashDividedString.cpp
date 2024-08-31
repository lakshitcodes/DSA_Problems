#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/hash-divided-string/description/

class Solution
{
public:
    char findChar(const std::string &s, int k, int start)
    {
        int total = 0;
        int limit = min(start + k, (int)s.length());
        for (int i = start; i < limit; i++)
        {
            total += s[i] - 'a';
        }
        total %= 26;
        return 'a' + total;
    }

    std::string stringHash(const std::string &s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string ans = "";
        for (int i = 0; i < s.length(); i += k)
        {
            ans += findChar(s, k, i);
        }
        return ans;
    }
};
