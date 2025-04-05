#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/two_sum/

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> map;
            vector<int> ans;
            for(int i=0;i<nums.size();i++){
                int diff=target-nums[i];
                if(map.count(diff)){
                    ans.push_back(map[diff]);
                    ans.push_back(i);
                    return ans;
                }
                map[nums[i]]=i;
            }
            return ans;
        }
    };