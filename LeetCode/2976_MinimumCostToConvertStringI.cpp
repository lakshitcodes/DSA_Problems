#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<vector<int>> distance(26, vector<int>(26, 1e7));
        for (int i = 0; i < 26; i++)
        {
            distance[i][i] = 0;
        }
        for (int i = 0; i < original.size(); i++)
        {
            distance[original[i] - 'a'][changed[i] - 'a'] = min(cost[i], distance[original[i] - 'a'][changed[i] - 'a']);
        }
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    int oc = distance[i][j];
                    int nc = distance[i][k] + distance[k][j];
                    if (nc < oc)
                    {
                        distance[i][j] = nc;
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.length(); i++)
        {
            if (source[i] != target[i])
            {
                int cost = distance[source[i] - 'a'][target[i] - 'a'];
                if (cost == 1e7)
                {
                    return -1;
                }
                ans += cost;
            }
        }
        return ans;
    }
};