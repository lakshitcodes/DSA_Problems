#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            // Using Kadane Algorithm
            // Once for maximizing positive sum, and other for minimizing megative sum
            // Then taking the max of those absolute values
            int currSum=0;
            int ans=0;
            for(auto &i : nums){
                currSum+=i;
                if(currSum<0){
                    currSum=0;
                }
                ans=max(currSum,ans);
            }
            int neg=0;
            currSum=0;
            for(int i : nums){
                currSum+=i;
                if(currSum>0){
                    currSum=0;
                }
                neg=min(neg,currSum);
            }
            return max(ans,abs(neg));
        }
    };