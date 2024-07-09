#include<bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/sort-a-stack/1

class Solution
{
public:
    void Reverse(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }
        int bottomElement = st.top();
        st.pop();
        stack<int> temp;
        while (!st.empty())
        {
            temp.push(bottomElement);
            bottomElement = st.top();
            st.pop();
        }
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        Reverse(st);
        st.push(bottomElement);
    }
};