#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-maximum-number-of-non-intersecting-substrings/

class Solution
{
public:
    int maxSubstrings(string word)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        vector<int> index(26, -1);
        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 'a';
            if (index[idx] != -1 && i - index[idx] + 1 >= 4)
            {
                ans++;
                for (int j = 0; j < 26; j++)
                {
                    index[j] = -1;
                }
            }
            else
            {
                if (index[idx] == -1)
                    index[idx] = i;
            }
        }
        return ans;
    }
};