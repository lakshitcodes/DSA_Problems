#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/finding-3-digit-even-numbers/

class Solution
{
public:
    bool possible(int val, vector<int> &num)
    {
        unordered_map<int, int> freq;
        while (val > 0)
        {
            freq[val % 10]++;
            val /= 10;
        }
        for (auto &i : freq)
        {
            if (num[i.first] < i.second)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> count(10, 0);
        for (auto &i : digits)
        {
            count[i]++;
        }
        vector<int> ans;
        for (int i = 100; i < 1000; i += 2)
        {
            if (possible(i, count))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};