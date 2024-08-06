#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

class Solution
{
public:
    int minimumPushes(string word)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> count(26, 0);
        for (auto &i : word)
        {
            count[i - 'a']++;
        }
        sort(count.rbegin(), count.rend());
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans += count[i] * (i / 8 + 1);
        }
        return ans;
    }
};