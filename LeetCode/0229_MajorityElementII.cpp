#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/majority-element-ii/

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int cnt1=0,cnt2=0,el1,el2;
            int n=nums.size();
    
            for(int i=0;i<nums.size();i++){
                if(cnt1==0 && nums[i]!=el2){
                    cnt1++;
                    el1=nums[i];
                }
                else if(cnt2==0 && nums[i]!=el1){
                    el2=nums[i];
                    cnt2++;
                }
                else if(nums[i]==el2){
                    cnt2++;
                }
                else if(nums[i]==el1){
                    cnt1++;
                }
                else{
                    cnt1--;cnt2--;
                }
            }
    
            cnt1=0,cnt2=0;
            for(auto &i : nums){
                cnt1+=i==el1;
                cnt2+=i==el2;
            }
            vector<int> ans;
            if(cnt1>=(n/3+1)){
                ans.push_back(el1);
            }
            if(cnt2>=(n/3+1)){
                ans.push_back(el2);
            }
            return ans;
        }
    };