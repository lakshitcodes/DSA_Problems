#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

class Solution
{
public:
    string preToInfix(string s)
    {
        stack<string> st;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                st.push(string(1, s[i]));
            }
            else
            {
                char oper = s[i];
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string temp = "(" + op1 + oper + op2 + ")";
                st.push(temp);
            }
        }
        return st.top();
    }
};