#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/vowel-spellchecker/

class Solution
{
public:
    string toLower(string s)
    {
        for (auto &i : s)
        {
            i = tolower(i);
        }
        return s;
    }
    string deVowelWord(string s)
    {
        s = toLower(s);
        for (auto &i : s)
        {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
            {
                i = '*';
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<string> orig(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive, deVowel;

        for (auto &word : wordlist)
        {
            string lower = toLower(word);
            string vowelless = deVowelWord(word);

            if (!caseInsensitive.count(lower))
            {
                caseInsensitive[lower] = word;
            }

            if (!deVowel.count(vowelless))
            {
                deVowel[vowelless] = word;
            }
        }

        vector<string> ans;
        for (auto &i : queries)
        {
            if (orig.count(i))
            {
                ans.push_back(i);
            }
            else if (caseInsensitive.count(toLower(i)))
            {
                ans.push_back(caseInsensitive[toLower(i)]);
            }
            else if (deVowel.count(deVowelWord(i)))
            {
                ans.push_back(deVowel[deVowelWord(i)]);
            }
            else
            {
                ans.push_back("");
            }
        }
        return ans;
    }
};