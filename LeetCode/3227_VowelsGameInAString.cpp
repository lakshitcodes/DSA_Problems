#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/vowels-game-in-a-string/description/

class Solution
{
public:
    bool doesAliceWin(string s)
    {
        int vowelCount = 0;

        for (char c : s)
        {
            if (isVowel(c))
            {
                vowelCount++;
            }
        }

        return vowelCount > 0;
    }

private:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};