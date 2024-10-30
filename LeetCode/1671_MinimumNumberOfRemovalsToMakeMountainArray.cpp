#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=nums.size();
        vector<int> dp1(n+1,1);
        vector<int> dp2(n+1,1);

        // Finding LIS upto each index
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
            }
        }
        // Finding LDS from each index to n
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    dp2[i] = max(dp2[i], 1 + dp2[j]);
                }
            }
        }
        int ans=n;
        // Finding the answer by considering each element as mountain and calculating accordingly
        for(int i=1;i<n-1;i++){
            // This condition is to check if this is mountain peak because to be a mountain peak atleast one element should be smaller on both sides
            if(dp1[i]>1 && dp2[i]>1)
                // +1 because current element is considered twice
                ans=min(ans,n-dp1[i]-dp2[i]+1);
        }
        return ans;
    }
};