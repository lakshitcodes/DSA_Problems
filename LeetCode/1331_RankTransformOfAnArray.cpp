#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/rank-transform-of-an-array

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (arr.size() == 0)
        {
            return {};
        }
        vector<int> copyArr = arr;
        sort(copyArr.begin(), copyArr.end());
        unordered_map<int, int> ranks;
        int smaller = 0;
        ranks[copyArr[0]] = 1;
        for (int i = 1; i < copyArr.size(); i++)
        {
            if (copyArr[i] > copyArr[i - 1])
            {
                smaller++;
            }
            ranks[copyArr[i]] = smaller + 1;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = ranks[arr[i]];
        }
        return arr;
    }
};