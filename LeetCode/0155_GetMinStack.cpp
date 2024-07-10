#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/min-stack/description/

class MinStack
{
public:
    stack<int> st, min;
    int k, v;
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        if (min.size() == 0 || val <= min.top())
        {
            min.push(val);
        }
    }

    void pop()
    {
        if (st.top() == min.top())
        {
            min.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min.top();
    }
};