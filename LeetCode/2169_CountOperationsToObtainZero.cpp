#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-operations-to-obtain-zero/

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        while (num1 && num2)
        {
            if (num1 > num2)
            {
                ans += num1 / num2;
                num1 %= num2;
            }
            else
            {
                ans += num2 / num1;
                num2 %= num1;
            }
        }
        return ans;
    }
};x