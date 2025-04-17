#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int ans=0;
            for(int i=0;i<nums.size();i++){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[i]==nums[j] && (i*j)%k==0){
                        ans++;
                    }
                }
            }
            return ans;
        }
    };