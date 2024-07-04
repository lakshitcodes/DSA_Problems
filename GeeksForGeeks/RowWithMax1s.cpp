#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int index = -1;
        int maxCount = 0;
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = m - 1;
            int ans = -1;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (arr[i][mid] == 1)
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if (ans != -1)
            {
                if (m - ans > maxCount)
                {
                    maxCount = m - ans;
                    index = i;
                }
            }
        }
        return index;
    }
};
