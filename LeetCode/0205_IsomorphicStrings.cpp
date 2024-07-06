#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/isomorphic-strings/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        if (s.length() == 0)
            return false;
        unordered_map<char, char> map;
        for (int i = 0; i < s.length(); i++)
        {
            if (map[s[i]])
            {
                if (map[s[i]] != t[i])
                    return false;
            }
            else
            {
                map[s[i]] = t[i];
            }
        }
        map.clear();
        swap(s, t);
        for (int i = 0; i < s.length(); i++)
        {
            if (map[s[i]])
            {
                if (map[s[i]] != t[i])
                    return false;
            }
            else
            {
                map[s[i]] = t[i];
            }
        }
        return true;
    }
};