#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int val = (k - s.length() % k) % k;
        s = s + string(val, fill);
        vector<string> ans;
        for (int i = 0; i < s.length(); i += k)
        {
            ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};