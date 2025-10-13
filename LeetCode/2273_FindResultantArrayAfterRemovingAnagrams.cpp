#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

class Solution
{
public:
    bool anagram(string a, string b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
    vector<string> removeAnagrams(vector<string> &words)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < words.size(); i++)
        {
            if (!anagram(ans.back(), words[i]))
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};