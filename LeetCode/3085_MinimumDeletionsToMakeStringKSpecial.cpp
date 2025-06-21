#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/

class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> count(26, 0);
        for (int i = 0; i < word.length(); i++)
        {
            count[word[i] - 'a']++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            int curr = 0;
            for (int j = 0; j < 26; j++)
            {
                if (count[j] < count[i])
                {
                    curr += count[j];
                }
                else if (count[j] - count[i] > k)
                {
                    curr += count[j] - count[i] - k;
                }
            }
            ans = min(ans, curr);
        }
        return ans;
    }
};