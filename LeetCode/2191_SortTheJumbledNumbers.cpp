#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sort-the-jumbled-numbers/description/

class Solution
{
public:
    static bool comparator(const vector<int> &a, const vector<int> &b)
    {
        return a[0] == b[0] ? a[2] < b[2] : a[0] < b[0];
    }
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<vector<int>> transformed;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int factor = 1;
            int oldNum = num;
            int newNum = 0;

            if (oldNum == 0)
            {
                newNum = mapping[0];
            }
            else
            {
                while (oldNum)
                {
                    newNum = mapping[oldNum % 10] * factor + newNum;
                    oldNum /= 10;
                    factor *= 10;
                }
            }
            transformed.push_back({newNum, num, i});
        }
        sort(transformed.begin(), transformed.end(), comparator);
        vector<int> result;

        for (auto &p : transformed)
        {
            result.push_back(p[1]);
        }
        return result;
    }
};