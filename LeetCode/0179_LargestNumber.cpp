#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/largest-number

class Solution
{
public:
    static bool comparator(string &a, string &b) { return a + b > b + a; }

    string largestNumber(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<string> arr;
        string ans = "";
        for (auto &i : nums)
        {
            arr.push_back(to_string(i));
        }
        sort(arr.begin(), arr.end(), comparator);
        for (auto &s : arr)
        {
            ans += s;
        }
        while (ans[0] == '0' && ans.length() > 1)
        {
            ans.erase(0, 1);
        }
        return ans;
    }
};