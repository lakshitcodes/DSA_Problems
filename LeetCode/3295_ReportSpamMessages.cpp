#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/report-spam-message/

class Solution
{
public:
    bool reportSpam(vector<string> &message, vector<string> &bannedWords)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count = 0;
        unordered_set<string> banned(bannedWords.begin(), bannedWords.end());
        for (auto &i : message)
        {
            if (banned.count(i))
            {
                count++;
            }
            if (count >= 2)
            {
                return true;
            }
        }
        return count >= 2;
    }
};