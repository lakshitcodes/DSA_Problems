#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-index-of-a-valid-split/

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            // Finding element with max frequency
            unordered_map<int,int> mp;
            for(auto &i : nums){
                mp[i]++;
            }
            int maxEle=-1;
            int right=0;
            for(auto &i : mp){
                if(2*i.second>nums.size()){
                    maxEle=i.first;
                    right=i.second;
                    break;
                }
            }
    
            // Finding Ans
            int left=0;
            int n=nums.size();
            for(int i=1;i<n;i++){
                if(nums[i-1]==maxEle){
                    left++;
                    right--;
                }
                if(2*left>i && 2*right>n-i){
                    return i-1;
                }
            }
            return -1;
        }
    };