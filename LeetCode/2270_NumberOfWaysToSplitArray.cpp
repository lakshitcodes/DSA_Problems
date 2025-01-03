#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/number-of-ways-to-split-array

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long rightSum = accumulate(nums.begin(),nums.end(),0LL);
        long long leftSum = 0;
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            rightSum-=nums[i];
            leftSum+=nums[i];
            cout<<rightSum<<" "<<leftSum<<endl;
            ans+= leftSum>=rightSum;
        }
        return ans;
    }
};