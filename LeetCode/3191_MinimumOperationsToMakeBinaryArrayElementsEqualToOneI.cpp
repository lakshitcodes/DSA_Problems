#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int ops=0;
            for(int i=0;i<nums.size()-2;i++){
                if(nums[i]==0){
                    ops++;
                    nums[i]=1;
                    nums[i+1]=!nums[i+1];
                    nums[i+2]=!nums[i+2];
                }
            }
            return nums[nums.size()-1] && nums[nums.size()-2] ? ops : -1;
        }
    };