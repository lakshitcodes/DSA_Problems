#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-the-number-of-good-subarrays/

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            unordered_map<int,int> occur;
            int n=nums.size();
            long long ans=0;
            int currPairs=0;
            int l=0,r=0;
            while(r<n){
                while(currPairs<k && r<n){
                    occur[nums[r]]++;
                    currPairs+=occur[nums[r]]-1;
                    r++;
                }
                while(currPairs>=k && l<r){
                    ans+=n-r+1;
                    currPairs-=occur[nums[l]]-1;
                    occur[nums[l]]--;
                    l++;
                }
            }
    
            return ans;
        }
    };