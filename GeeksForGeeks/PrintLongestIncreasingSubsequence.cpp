#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

// Here we keep a hash array to store the index of the prev smaller element while checking if it forms the part of the longest subsequence that ends at the current index.
class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        vector<int> dp(n, 1), hash(n, 0);
        if (n == 1)
        {
            return arr;
        }
        int maxLen = 0;
        int maxInd = -1;
        for (int ind = 1; ind < n; ind++)
        {
            hash[ind] = ind;
            for (int prev = 0; prev < ind; prev++)
            {
                if (arr[prev] < arr[ind])
                {
                    int newLen = 1 + dp[prev];
                    if (dp[ind] < newLen)
                    {
                        hash[ind] = prev;
                        dp[ind] = newLen;
                    }
                }
                if (dp[ind] > maxLen)
                {
                    maxLen = dp[ind];
                    maxInd = ind;
                }
            }
        }
        vector<int> ans;
        ans.push_back(arr[maxInd]);
        maxLen--;
        while (hash[maxInd] != maxInd && maxLen--)
        {
            maxInd = hash[maxInd];
            ans.push_back(arr[maxInd]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};