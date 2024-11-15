#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = arr.size();

        // Finding the longest non-decreasing prefix;
        int left = 0;
        while(left<n-1 && arr[left]<=arr[left+1]){
            left++;
        }

        if(left==n-1){
            return 0;
        }

        // Finding the longest non-decreasing suffix;
        int right = n-1;
        while(right>0 && arr[right-1]<=arr[right]){
            right--;
        }

        if(right==0){
            return n-1;
        }
        int result = min(n-left-1,right);

        // Two pointers and BS to remove smallest middle part
        int i=0,j=right;
        while(i<=left && j<n){
            if(arr[i]<=arr[j]){
                result = min(result,j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};