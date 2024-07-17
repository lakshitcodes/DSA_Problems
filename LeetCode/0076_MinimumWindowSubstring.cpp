#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-window-substring/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int s_length = s.length();
        int t_length = t.length();

        if (t_length > s_length)
        {
            return "";
        }

        unordered_map<char, int> count;

        // Initialize count map for characters in string t
        for (char c : t)
        {
            count[c]++;
        }

        int i = 0;                    // Left pointer of the window
        int j = 0;                    // Right pointer of the window
        int requiredChars = t_length; // Number of characters to match

        int ansStart = -1;       // Start index of the minimum window
        int ansLength = INT_MAX; // Length of the minimum window

        while (j < s_length)
        {
            if (count[s[j]] > 0)
            {
                // This character in s is required
                requiredChars--;
            }

            count[s[j]]--;
            j++;

            while (requiredChars == 0)
            {
                // Update the minimum window
                if (j - i < ansLength)
                {
                    ansLength = j - i;
                    ansStart = i;
                }

                // Move the left pointer to the right
                count[s[i]]++;
                if (count[s[i]] > 0)
                {
                    requiredChars++;
                }

                i++;
            }
        }

        return (ansStart == -1) ? "" : s.substr(ansStart, ansLength);
    }
};
