#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/house-robber-iv/

class Solution {
    public:
        bool isPossible(vector<int> &nums,int k,int val){
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=val){
                    k--;i++;
                }
            }
            return k<=0;
        }
        int minCapability(vector<int>& nums, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int l=*min_element(nums.begin(),nums.end());
            int r=*max_element(nums.begin(),nums.end());
    
            while(l<=r){
                int mid=l + (r-l)/2;
                if(isPossible(nums,k,mid)){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return r+1;
        }
    };