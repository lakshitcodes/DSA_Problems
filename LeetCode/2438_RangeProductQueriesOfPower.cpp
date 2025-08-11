#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/range-product-queries-of-power/

class Solution
{
public:
    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> powers;
        for (int i = 0; i < 31; i++)
        {
            if (n & (1 << i))
            {
                powers.push_back(1 << i);
            }
        }
        vector<int> products;
        const int mod = 1e9 + 7;

        for (int i = 0; i < queries.size(); i++)
        {
            long long ans = 1;
            for (int l = queries[i][0]; l <= queries[i][1]; l++)
            {
                ans = (ans * powers[l]) % mod;
            }
            products.push_back(ans);
        }
        return products;
    }
};