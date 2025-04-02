#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/

// Time Complexity : O(n)
// Space Complexity : O(n)
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            if(nums.size()<3){
                return 0;
            }
            int n=nums.size();
            vector<int> left(n,0),right(n,0);
            for(int i=1;i<n-1;i++){
                left[i]=max(left[i-1],nums[i-1]);
            }
            for(int i=n-2;i>=1;i--){
                right[i]=max(right[i+1],nums[i+1]);
            }
            long long ans=0;
            for(int i=1;i<n-1;i++){
                ans=max(ans,(long long)(left[i]-nums[i])*right[i]);
            }
            return ans;
        }
    
    };

// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            if(nums.size()<3){
                return 0;
            }
            long long ans=0;
            long long l=nums[0];
            long long maxD=max(0LL,l-nums[1]);
            for(int i=2;i<nums.size();i++){
                l=max(l,(long long)nums[i-2]);
                maxD=max(maxD,l-nums[i-1]);
                ans=max(ans,maxD*nums[i]);
            }
            return ans;
        }
    
    };