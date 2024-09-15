#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts

class Solution
{
public:
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    void increment(char c)
    {
        a += c == 'a';
        e += c == 'e';
        i += c == 'i';
        o += c == 'o';
        u += c == 'u';
    }
    string createMask()
    {
        return to_string(a % 2) + to_string(e % 2) + to_string(i % 2) + to_string(o % 2) + to_string(u % 2);
    }
    int findTheLongestSubstring(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string mask = "00000";
        unordered_map<string, int> dp;
        dp[mask] = -1;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            increment(s[i]);
            string currMask = createMask();
            if (dp.count(currMask))
            {
                ans = max(ans, i - dp[currMask]);
            }
            else
            {
                dp[currMask] = i;
            }
        }
        return ans;
    }
};