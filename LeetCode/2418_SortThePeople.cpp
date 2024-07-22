#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sort-the-people

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<pair<int, string>> sortTemp;
        for (int i = 0; i < names.size(); i++)
        {
            sortTemp.push_back({heights[i], names[i]});
        }
        sort(sortTemp.rbegin(), sortTemp.rend());
        for (int i = 0; i < sortTemp.size(); i++)
        {
            names[i] = sortTemp[i].second;
        }
        return names;
    }
};