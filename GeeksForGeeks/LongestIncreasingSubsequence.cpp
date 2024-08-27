#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

/*
Initialization:

Start with an empty array dp. This array will store the smallest possible tail value for all increasing subsequences of different lengths found so far.
Iteration:

Iterate through each element in the input array.
For each element num, determine its position in the dp array using binary search.
Binary Search Operation:

Use the binary search to find the first element in dp that is greater than or equal to num. (lower bound)
If such an element is found, replace it with num, as num can potentially start a longer increasing subsequence.
If num is larger than any element in dp, append num to dp, extending the longest subsequence found so far.
Final Result:

The length of the dp array at the end of the iteration is the length of the LIS. The array dp itself does not necessarily represent the actual subsequence but helps in determining the length efficiently.
*/

class Solution
{
public:
    int longestSubsequence(int n, int arr[])
    {
        vector<int> temp;
        temp.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > temp.back())
            {
                temp.push_back(arr[i]);
            }
            else
            {
                int lowerIndex = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[lowerIndex] = arr[i];
            }
        }
        return temp.size();
    }
};