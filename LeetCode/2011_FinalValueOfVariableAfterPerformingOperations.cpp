#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/final-value-variable-after-performing-operations/

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int val = 0;
        for (auto &i : operations)
        {
            if (i[1] == '+')
            {
                val++;
            }
            else
            {
                val--;
            }
        }
        return val;
    }
};