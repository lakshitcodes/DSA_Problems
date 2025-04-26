#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            long long ans=0;
            int n=nums.size();
            int maxi=-1,mini=-1;
            for(int r=0,l=0;r<n;r++){
                int val=nums[r];
                if(val<minK || val>maxK){
                    l=r+1;
                }
                if(val==minK){
                    mini=r;
                }
                if(val==maxK){
                    maxi=r;
                }
                ans+=max(min(mini,maxi)-l+1,0);
            }
            return ans;
        }
    };