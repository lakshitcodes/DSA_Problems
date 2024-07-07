#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/

class Solution
{
public:
    void fillArray(int n, string curr, int zero, int one, vector<string> &ans)
    {
        if (n == 0)
        {
            if (one)
                ans.push_back(curr);
            return;
        }
        if (curr.empty() || curr.back() == '1')
            fillArray(n - 1, curr + '0', zero + 1, one, ans);

        fillArray(n - 1, curr + '1', zero, one + 1, ans);
    }
    vector<string> validStrings(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (n == 1)
        {
            return {"0", "1"};
        }
        vector<string> ans;
        fillArray(n, "", 0, 0, ans);
        return ans;
    }
};