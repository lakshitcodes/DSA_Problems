#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-subsequence-repeated-k-times/

class Solution
{
public:
    bool isPossible(string s, int k, string curr)
    {
        int n = curr.length();
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == curr[j])
            {
                j++;
                if (j == n)
                {
                    j = 0;
                    k--;
                }
            }
        }
        return k <= 0;
    }
    string longestSubsequenceRepeatedK(string s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> freq(26, 0);
        for (auto &i : s)
        {
            freq[i - 'a']++;
        }
        vector<char> candidates;
        for (int i = 25; i >= 0; i--)
        {
            if (freq[i] >= k)
            {
                candidates.push_back(i + 'a');
            }
        }

        queue<string> q;
        for (char ch : candidates)
        {
            q.push(string(1, ch));
        }
        string ans = "";
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            if (curr.size() > ans.size())
            {
                ans = curr;
            }

            for (auto &i : candidates)
            {
                string temp = curr + i;
                if (isPossible(s, k, temp))
                {
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};