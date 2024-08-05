#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/kth-distinct-string-in-an-array/description/

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<string, int> st;

        for (auto &i : arr)
        {
            st[i]++;
        }
        for (auto &i : arr)
        {
            if (st[i] == 1)
            {
                k--;
                if (k == 0)
                {
                    return i;
                }
            }
        }
        return "";
    }
};