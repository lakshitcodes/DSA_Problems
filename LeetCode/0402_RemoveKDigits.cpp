#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/remove-k-digits/description/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.length())
            return "0";
        stack<char> s1;
        for (int i = 0; i < num.length(); i++)
        {
            while (k > 0 && !s1.empty() && s1.top() > num[i])
            {
                s1.pop();
                k--;
            }
            s1.push(num[i]);
        }
        while (k > 0)
        {
            s1.pop();
            k--;
        }
        string ans = "";
        while (!s1.empty())
        {
            ans += s1.top();
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        int count = 0;
        while (ans[count] == '0')
        {
            count++;
        }
        cout << count;
        if (count)
        {
            ans = ans.substr(count);
        }
        return ans == "" ? "0" : ans;
    }
};