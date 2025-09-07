#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-unique-integers-sum-upto-zero/

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        if (n & 1)
        {
            ans.push_back(0);
        }
        for (int i = 1; i < n; i += 2)
        {
            ans.push_back(i + 1);
            ans.push_back(-(i + 1));
        }
        return ans;
    }
};