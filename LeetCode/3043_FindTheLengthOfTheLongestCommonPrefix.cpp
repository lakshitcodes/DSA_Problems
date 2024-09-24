#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<string> first;
        for (auto num : arr1)
        {
            string curr = to_string(num);
            string temp = "";
            for (int i = 0; i < curr.length(); i++)
            {
                temp += curr[i];
                first.insert(temp);
            }
        }
        int ans = 0;
        for (auto num : arr2)
        {
            string curr = to_string(num);
            string temp = "";
            for (auto &c : curr)
            {
                temp += c;
                if (first.count(temp))
                {
                    ans = max(ans, (int)temp.length());
                }
            }
        }
        return ans;
    }
};