#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/asteroid-collision/

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &a)
    {
        stack<int> s;
        s.push(a[0]);
        for (int i = 1; i < a.size(); i++)
        {
            if (s.size() == 0)
            {
                s.push(a[i]);
                continue;
            }
            int top = s.top();
            if ((top > 0 && a[i] > 0) || (top < 0 && a[i] < 0) || (top < 0 && a[i] > 0))
                s.push(a[i]);
            else
            {
                while (!s.empty() && abs(top) < abs(a[i]) && (top > 0 && a[i] < 0))
                {
                    s.pop();
                    top = s.size() > 0 ? s.top() : 0;
                }
                if (s.empty())
                    s.push(a[i]);
                else if (top + a[i] == 0)
                    s.pop();
                else if (abs(top) == abs(a[i]) || (top < 0 && a[i] < 0))
                    s.push(a[i]);
            }
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};