#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution {
public:
    int solve(int index,int currOr,int maxOr,vector<int> &nums){
        if(index==nums.size()){
            return currOr==maxOr;
        }
        int include = solve(index+1,currOr|nums[index],maxOr,nums);
        int exclude = solve(index+1,currOr,maxOr,nums);
        return include+exclude;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);


        int maxOr=0;
        for(auto &i : nums){
            maxOr|=i;
        }

        return solve(0,0,maxOr,nums);
    }
};