#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/

class Solution
{
public:
    int minimumDeletions(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = s.length();
        vector<int> leftB(n, 0), rightA(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'b')
            {
                leftB[i + 1] = 1 + leftB[i];
            }
            else
            {
                leftB[i + 1] = leftB[i];
            }
        }
        for (int i = n - 1; i >= 1; i--)
        {
            if (s[i] == 'a')
            {
                rightA[i - 1] = 1 + rightA[i];
            }
            else
            {
                rightA[i - 1] = rightA[i];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, leftB[i] + rightA[i]);
        }
        return ans;
    }
};