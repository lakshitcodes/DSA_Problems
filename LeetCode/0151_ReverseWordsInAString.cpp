#include<bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/reverse-words-in-a-string/

class Solution
{
public:
    string reverseWords(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<string> store;
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                temp += s[i];
            }
            else
            {
                if (temp.size())
                {
                    store.push_back(temp);
                    temp = "";
                }
            }
        }
        if (temp.size())
        {
            store.push_back(temp);
        }
        string ans = "";
        for (int i = store.size() - 1; i >= 0; i--)
        {
            if (ans.length())
            {
                ans += ' ';
            }
            ans += store[i];
        }
        return ans;
    }
};