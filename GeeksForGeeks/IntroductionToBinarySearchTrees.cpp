#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/binary-search-trees/1

class Solution
{
public:
    bool isBSTTraversal(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i)
        {
            if (arr[i] >= arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};