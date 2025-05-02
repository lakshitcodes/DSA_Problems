#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/push-dominoes/

class Solution
{
public:
    string pushDominoes(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = s.length();
        vector<int> left(n, 0), right(n, 0);
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr)
            {
                curr++;
            }
            if (s[i] == 'L')
            {
                curr = 0;
            }
            else if (s[i] == 'R')
            {
                curr = 1;
            }
            right[i] = curr;
        }
        curr = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (curr)
            {
                curr++;
            }
            if (s[i] == 'R')
            {
                curr = 0;
            }
            else if (s[i] == 'L')
            {
                curr = 1;
            }
            left[i] = curr;
        }
        for (auto &i : left)
        {
            cout << i << " ";
        }
        cout << endl;
        for (auto &i : right)
        {
            cout << i << " ";
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {
                if (left[i] != 0 && (left[i] < right[i] || right[i] == 0))
                {
                    s[i] = 'L';
                }
                else if (right[i] != 0 && (right[i] < left[i] || left[i] == 0))
                {
                    s[i] = 'R';
                }
            }
        }
        return s;
    }
};