#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/valid-parentheses/description/

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    return false;
                }
                if (s[i] == ')')
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else if (s[i] == '}')
            {
                if (st.empty())
                {
                    return false;
                }
                if (s[i] == '}')
                {
                    if (st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else if (s[i] == ']')
            {
                if (st.empty())
                {
                    return false;
                }
                if (s[i] == ']')
                {
                    if (st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};