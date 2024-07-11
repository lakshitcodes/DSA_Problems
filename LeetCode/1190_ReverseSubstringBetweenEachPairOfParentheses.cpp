#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                string temp;
                while (st.top() != '(')
                {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                // reverse(temp.begin(),temp.end());
                for (int j = 0; j < temp.length(); j++)
                {
                    st.push(temp[j]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};