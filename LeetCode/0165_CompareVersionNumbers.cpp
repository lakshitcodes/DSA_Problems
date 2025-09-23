#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/compare-version-numbers/

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (version1 == version2)
        {
            return 0;
        }
        vector<int> v1;
        int val = 0;
        for (int i = 0; i < version1.length(); i++)
        {
            if (version1[i] == '.')
            {
                v1.push_back(val);
                val = 0;
            }
            else
            {
                val = val * 10 + (version1[i] - '0');
            }
        }
        if (val)
        {
            v1.push_back(val);
        }
        vector<int> v2;
        val = 0;
        for (int i = 0; i < version2.length(); i++)
        {
            if (version2[i] == '.')
            {
                v2.push_back(val);
                val = 0;
            }
            else
            {
                val = val * 10 + (version2[i] - '0');
            }
        }
        if (val)
        {
            v2.push_back(val);
        }
        if (v1.size() > v2.size())
        {
            int freq = v1.size() - v2.size();
            for (int i = 0; i < freq; i++)
            {
                v2.push_back(0);
            }
        }
        if (v2.size() > v1.size())
        {
            int freq = v2.size() - v1.size();
            for (int i = 0; i < freq; i++)
            {
                v1.push_back(0);
            }
        }
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] > v2[i])
            {
                return 1;
            }
            if (v1[i] < v2[i])
            {
                return -1;
            }
        }
        return 0;
    }
};