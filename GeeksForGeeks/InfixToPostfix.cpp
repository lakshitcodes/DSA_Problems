#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

class Solution
{
public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        unordered_map<char, int> prec;
        prec['*'] = prec['/'] = 3;
        prec['+'] = prec['-'] = 2;
        prec['^'] = 4;
        prec['('] = prec[')'] = -1;
        stack<char> st;
        string ans = "";
        for (auto i : s)
        {
            if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
            {
                ans += i;
            }
            else
            {
                if (i == '(')
                {
                    st.push(i);
                }
                else if (i == ')')
                {
                    while (st.top() != '(')
                    {
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    while (!st.empty() && prec[i] <= prec[st.top()])
                    {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(i);
                }
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