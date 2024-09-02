#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= sum;
        for (int i = 0; i < chalk.size(); i++)
        {
            if (chalk[i] > k)
            {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};