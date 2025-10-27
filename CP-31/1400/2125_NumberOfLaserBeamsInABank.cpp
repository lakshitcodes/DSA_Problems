#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        int prev = 0;
        for (auto &r : bank)
        {
            int curr = 0;
            for (auto &i : r)
            {
                if (i == '1')
                {
                    curr++;
                }
            }
            ans += curr * prev;
            if (curr != 0)
            {
                prev = curr;
            }
        }
        return ans;
    }
};