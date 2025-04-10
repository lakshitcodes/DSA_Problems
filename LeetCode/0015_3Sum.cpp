#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/3sum/

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            int n=nums.size();
        
            for(int i=0;i<nums.size();i++){
                int low=i+1;
                int high=n-1;
                while(low<high){
                    int target=nums[i]+nums[low]+nums[high];
                    if(target>0){
                        high--;
                    }
                    else if(target<0){
                        low++;
                    }
                    else{
                        ans.push_back({nums[i],nums[low],nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(i+1 < n && nums[i] == nums[i+1]) i++;
            }
            return ans;
        }
    };