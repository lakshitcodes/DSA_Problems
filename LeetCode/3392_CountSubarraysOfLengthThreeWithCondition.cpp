#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if(nums.size()<3){
            return 0;
        }
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            if(2*(nums[i]+nums[i+2])==nums[i+1]){
                ans++;
            }
        }
        return ans;
    }
};