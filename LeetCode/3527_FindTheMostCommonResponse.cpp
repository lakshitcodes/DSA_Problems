#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-most-common-response/

class Solution
{
public:
    string findCommonResponse(vector<vector<string>> &responses)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<string, int> mp;
        for (auto &i : responses)
        {
            set<string> st(i.begin(), i.end());
            for (auto &j : st)
            {
                mp[j]++;
            }
        }

        string ans = "";
        int count = 0;
        for (auto &i : mp)
        {
            if (i.second > count)
            {
                count = i.second;
                ans = i.first;
            }
            else if (i.second == count)
            {
                if (i.first < ans)
                {
                    ans = i.first;
                }
            }
        }
        return ans;
    }
};