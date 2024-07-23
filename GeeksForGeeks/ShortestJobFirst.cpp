#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/shortest-job-first/1

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = ratings.size();
        vector<int> candy(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }
        return accumulate(candy.begin(), candy.end(), 0);
    }
};