#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-words-containing-character

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        for (int i = 0; i < words.size(); i++)
        {
            for (auto &j : words[i])
            {
                if (j == x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};