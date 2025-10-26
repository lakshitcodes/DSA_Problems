#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/remove-zeros-in-decimal-representation/

class Solution
{
public:
    long long removeZeros(long long n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string val = to_string(n);
        string ans = "";
        for (auto &i : val)
        {
            if (i != '0')
            {
                ans += i;
            }
        }
        return stoll(ans);
    }
};