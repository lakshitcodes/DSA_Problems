#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/zero-array-transformation-ii/

class Solution {
    public:
        bool possible(vector<int> &nums,vector<vector<int>> &queries,int k){
            int n=nums.size();
            vector<int> diff(n+1,0);
            for(int i=0;i<=k;i++){
                int l=queries[i][0];
                int r=queries[i][1];
                int val=queries[i][2];
                diff[l]+=val;
                diff[r+1]-=val;
            }
            if(nums[0]>diff[0]){
                return false;
            }
            for(int i=1;i<n;i++){
                diff[i]+=diff[i-1];
                if(nums[i]>diff[i]){
                    return false;
                }
            }
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            bool flag=true;
            for(auto &i : nums){
                if(i>0){
                    flag=false;
                }
            }
    
            if(flag){
                return 0;
            }
    
            int l=0,r=queries.size()-1;
            int ans=-2;
            while(l<=r){
                int mid = l+ (r-l)/2;
                if(possible(nums,queries,mid)){
                    ans=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            return ans+1;
        }
    };