#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/valid-anagram/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.length();
        int p = t.length();
        if (n != p)
        {
            return false;
        }
        int arr1[26];
        for (int i = 0; i < 26; i++)
        {
            arr1[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            arr1[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            arr1[t[i] - 'a']--;
        }
        bool flag = true;
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != 0)
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};