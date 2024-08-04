#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-number-of-winning-players/

class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(11, 0);
            mp[i] = temp;
        }
        for (auto &i : pick)
        {
            mp[i[0]][i[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (mp[i][j] >= i + 1)
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};