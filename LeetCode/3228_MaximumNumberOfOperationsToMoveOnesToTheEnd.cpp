#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/

class Solution
{
public:
    int maxOperations(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = s.length();
        vector<int> onePos;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                onePos.push_back(i);
            }
        }
        vector<int> storeResult(onePos.size(), 0);
        for (int i = onePos.size() - 1; i >= 0; i--)
        {
            if (onePos[i] != n - 1 && i == onePos.size() - 1)
            {
                storeResult[i] = 1;
            }
            else if (i != onePos.size() - 1)
            {
                if (onePos[i] + 1 == onePos[i + 1])
                {
                    storeResult[i] = storeResult[i + 1];
                }
                else
                {
                    storeResult[i] = 1 + storeResult[i + 1];
                }
            }
        }
        return accumulate(storeResult.begin(), storeResult.end(), 0);
    }
};