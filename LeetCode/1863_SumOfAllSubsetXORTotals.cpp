#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {
    public:
        int solve(int currXor,int idx,vector<int> &nums){
            if(idx==nums.size()){
                return currXor;
            }
            return solve(currXor,idx+1,nums)+solve(currXor^nums[idx],idx+1,nums);
        }
        int subsetXORSum(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            return solve(0,0,nums);
        }
    };