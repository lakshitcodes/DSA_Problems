#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/

class Solution
{
public:
    void deleteSmallest(vector<char> &curr)
    {
        if (curr.empty())
            return; // Check if the vector is empty

        int n = curr.size();
        int idx = n - 1;
        char c = curr[idx];

        // Find the index of the smallest character
        for (int i = n - 1; i >= 0; --i)
        {
            if (curr[i] < c)
            {
                c = curr[i];
                idx = i;
            }
        }
        curr.erase(curr.begin() + idx); // Remove the smallest character
    }

    string clearStars(string s)
    {
        vector<char> curr;
        for (char i : s)
        {
            if (i == '*')
            {
                deleteSmallest(curr);
            }
            else
            {
                curr.push_back(i);
            }
        }

        // Construct the result string from the vector
        string ans(curr.begin(), curr.end());
        return ans;
    }
};