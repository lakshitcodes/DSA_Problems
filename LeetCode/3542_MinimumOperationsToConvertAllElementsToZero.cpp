#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-operations-to-convert-all-elements-equal-to-zero/

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        static bool seen[100001];
        memset(seen, 0, sizeof(seen));
        static int monoStackArr[200000];

        int top = 0;
        for (int curr : nums)
        {
            if (curr == 0)
            {
                while (top)
                {
                    seen[monoStackArr[--top]] = false;
                }
                continue;
            }
            while (top && monoStackArr[top - 1] > curr)
            {
                seen[monoStackArr[--top]] = false;
            }
            if (!seen[curr])
            {
                ++ans;
                seen[curr] = true;
            }
            monoStackArr[top++] = curr;
        }
        return ans;
    }
};