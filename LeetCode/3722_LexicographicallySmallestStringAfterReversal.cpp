#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lexicographically-smallest-string-after-reversal/

class Solution
{
public:
    string lexSmallest(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string ans = s;
        for (int i = 0; i < s.length(); i++)
        {
            string first = s;
            string last = s;

            reverse(first.begin(), first.begin() + i + 1);
            reverse(last.begin() + i + 1, last.end());
            ans = min(ans, first);
            ans = min(ans, last);
        }

        return ans;
    }
};