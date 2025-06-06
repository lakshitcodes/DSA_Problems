#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

class Solution
{
public:
    string robotWithString(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
        }
        stack<char> st;
        string ans = "";
        char minChar = 'a';
        for (auto &i : s)
        {
            st.push(i);
            count[i - 'a']--;
            while (minChar <= 'z' && count[minChar - 'a'] == 0)
            {
                minChar++;
            }
            while (!st.empty() && st.top() <= minChar)
            {
                ans += st.top();
                st.pop();
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};