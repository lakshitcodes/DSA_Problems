#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/parsing-a-boolean-expression/

class Solution
{
public:
    char parseAnd(string exp)
    {
        bool ans = true;
        for (auto &i : exp)
        {
            ans &= i == 't';
        }
        return ans ? 't' : 'f';
    }
    char parseNot(string exp)
    {
        if (exp[0] == 't')
        {
            return 'f';
        }
        return 't';
    }
    char parseOr(string expression)
    {
        bool ans = false;
        for (auto &i : expression)
        {
            ans |= i == 't';
        }
        return ans ? 't' : 'f';
    }
    bool parseBoolExpr(string expression)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        stack<char> st;
        stack<char> operation;
        for (auto &i : expression)
        {
            if (i == ',')
            {
                continue;
            }
            if (i == '!' || i == '&' || i == '|')
            {
                operation.push(i);
            }
            else if (i != ')')
            {
                st.push(i);
            }
            else
            {
                string operands = "";
                while (st.top() != '(')
                {
                    operands += st.top();
                    st.pop();
                }
                st.pop();
                if (operation.top() == '&')
                {
                    st.push(parseAnd(operands));
                }
                if (operation.top() == '!')
                {
                    st.push(parseNot(operands));
                }
                if (operation.top() == '|')
                {
                    st.push(parseOr(operands));
                }
                operation.pop();
            }
        }
        return st.top() == 't';
    }
};