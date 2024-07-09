#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/subset-sums2234/1

class Solution
{
public:
    void solve(int currSum, int index, vector<int> &ans, vector<int> &arr)
    {
        if (index == arr.size())
        {
            ans.push_back(currSum);
            return;
        }
        solve(currSum, index + 1, ans, arr);
        solve(currSum + arr[index], index + 1, ans, arr);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        solve(0, 0, ans, arr);
        return ans;
    }
};