#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/crawler-log-folder/description

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> st;
        for (int i = 0; i < logs.size(); i++)
        {
            int n = logs[i].size();
            if (logs[i][n - 1] == '/')
            {
                if (logs[i][n - 2] == '.')
                {
                    if (n == 2)
                    {
                        continue;
                    }
                    if (logs[i][n - 3] == '.')
                    {
                        if (!st.empty())
                            st.pop();
                    }
                }
                else
                {
                    st.push(logs[i]);
                }
            }
        }
        int counter = 0;
        while (!st.empty())
        {
            st.pop();
            counter++;
        }
        return counter;
    }
};