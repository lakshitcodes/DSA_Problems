#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

// Self Implemented
// Time Complexity : O(2^n
class Solution {
public:
    char findKthBit(int n, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string ans="0";
        for(int i=1;i<n && ans.length()<k;i++){
            ans+='1';
            for(int j=ans.length()-2;j>=0;j--){
                ans+= ans[j]=='0' ? '1' : '0';
            }
        }
        return ans[k-1];
    }
};


// LeetCode Solution
class Solution {
public:
    char findKthBit(int n, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // Base Case : When n==1, the only string is "0"
        if (n == 1) {
            return '0';
        }

        // The length of the current string is 2^n-1
        int length = (1 << n) - 1;

        // Find the middle index
        int middle = length / 2 + 1;

        // If k is the middle return 1
        if (k == middle)
            return '1';

        // If k is in the left part ,find the bit in Sn-1
        if (k < middle)
            return findKthBit(n - 1, k);

        // If k is in the right part, find the bit in Sn-1 and invert it
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};