#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/applying-operations-to-an-array/

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n=nums.size();
            vector<int> ans(n,0);
            int i=0;
            for(int j=0;j<n;j++){
                if(nums[j]!=0){
                    ans[i]=nums[j];
                    i++;
                }
            }
            nums=ans;
        }
        vector<int> applyOperations(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]==nums[i+1]){
                    nums[i]=nums[i]+nums[i+1];
                    nums[i+1]=0;
                    i++;
                }
            }
            moveZeroes(nums);
            return nums;
        }
    };