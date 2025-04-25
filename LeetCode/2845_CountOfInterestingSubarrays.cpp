#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-of-interesting-subarrays/

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n=nums.size();
            long long prefix=0;
            long long ans=0;
            unordered_map<long long,long long> mp;
            mp[0]++;
            for(int i=0;i<n;i++){
                if(nums[i]%modulo==k){
                    prefix++;
                }
                prefix%=modulo;
                if(mp.find((prefix-k+modulo)%modulo)!=mp.end()){
                    ans+=mp[(prefix-k+modulo)%modulo];
                }
                mp[prefix]++;
            }
            return ans;
        }
    };