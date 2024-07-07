#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-encrypted-string/

class Solution
{
public:
    string getEncryptedString(string s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans += s[(i + k) % n];
        }
        return ans;
    }
};