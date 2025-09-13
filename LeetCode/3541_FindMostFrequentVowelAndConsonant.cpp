#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-most-common-vowel-and-consonant/

class Solution
{
public:
    int maxFreqSum(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<char, int> mp;
        for (auto &i : s)
        {
            mp[i]++;
        }
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int vowel = 0, conso = 0;
        for (auto &i : mp)
        {
            if (vowels.count(i.first))
            {
                vowel = max(vowel, i.second);
            }
            else
            {
                conso = max(conso, i.second);
            }
        }
        return vowel + conso;
    }
};