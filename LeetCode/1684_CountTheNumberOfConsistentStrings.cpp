#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-the-number-of-consistent-strings

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        unordered_set<char> input(allowed.begin(), allowed.end());
        for (auto &i : words)
        {
            bool valid = true;
            for (auto &c : i)
            {
                if (input.find(c) == input.end())
                {
                    valid = false;
                    break;
                }
            }
            ans += valid;
        }
        return ans;
    }
};