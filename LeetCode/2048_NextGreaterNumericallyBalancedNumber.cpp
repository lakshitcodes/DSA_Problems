#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/next-greater-numerically-balanced-number/

class Solution
{
public:
    int nextBeautifulNumber(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        for (int i = n + 1; i <= 1224444; i++)
        {
            vector<int> freq(10, 0);
            string curr = to_string(i);
            for (auto &c : curr)
            {
                freq[c - '0']++;
            }
            bool valid = true;
            for (int j = 0; j < 10; j++)
            {
                if (freq[j] && freq[j] != j)
                {
                    valid = false;
                }
            }
            if (valid)
            {
                return i;
            }
        }
        return 0;
    }
};