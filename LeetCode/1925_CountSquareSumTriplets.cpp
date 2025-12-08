#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-sqaure-sum-triplets/

class Solution
{
public:
    int countTriples(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int val = sqrt(i * i + j * j);
                if (val <= n && val * val == i * i + j * j)
                {
                    count += 2;
                }
            }
        }
        return count;
    }
};