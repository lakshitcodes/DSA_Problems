#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-complete-subarrays-in-an-array/

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int ans=0;
    
            unordered_set<int> st(nums.begin(),nums.end());
            int unique=st.size();
            int l=0,r=0;
            int n=nums.size();
            unordered_map<int,int> ele;
            while(r<n){
                ele[nums[r]]++;
                while(ele.size()>=unique){
                    ans+=n-r;
                    ele[nums[l]]--;
                    if(ele[nums[l]]==0){
                        ele.erase(nums[l]);
                    }
                    l++;
                }
                r++;
            }
            return ans;
    
        }
    };