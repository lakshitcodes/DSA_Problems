#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-senior-citizens/

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        for (auto &i : details)
        {
            int age = i[11] - '0';
            age = age * 10 + (i[12] - '0');
            if (age > 60)
            {
                ans++;
            }
        }
        return ans;
    }
};