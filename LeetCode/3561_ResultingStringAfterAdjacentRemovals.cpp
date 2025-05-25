#include <bits/stdc++.h>
using namespace std;

// Question Link : http://leetcode.com/problems/resulting-string-after-adjacent-removals/

class Solution
{
public:
    string resultingString(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (s.length() < 2)
        {
            return s;
        }

        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
                continue;
            }
            int val1 = (st.top() - 'a');
            int val2 = (s[i] - 'a');
            if ((val1 + 1) % 26 == val2 || (val1 - 1 + 26) % 26 == val2)
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};