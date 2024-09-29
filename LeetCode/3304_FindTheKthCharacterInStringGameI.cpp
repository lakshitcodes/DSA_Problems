#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/

class Solution
{
public:
    string generate(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'z')
            {
                ans += 'a';
            }
            else
            {
                ans += s[i] + 1;
            }
        }
        return ans;
    }
    char kthCharacter(int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string temp = string(1, 'a');
        while (temp.length() < k)
        {
            temp += generate(temp);
        }
        return temp[k - 1];
    }
};