#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

class Solution
{
public:
    string solve(string s, int a, int b, unordered_set<string> &visited)
    {
        if (visited.count(s))
        {
            return s;
        }
        visited.insert(s);
        string ans = s;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 1; j < s.length(); j += 2)
            {
                s[j] = ((s[j] - '0' + a) % 10) + '0';
            }
            ans = min(ans, solve(s, a, b, visited));
        }

        rotate(s.begin(), s.begin() + (s.length() - b), s.end());
        ans = min(ans, solve(s, a, b, visited));

        return ans;
    }
    string findLexSmallestString(string s, int a, int b)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<string> visited;
        return solve(s, a, b, visited);
    }
};