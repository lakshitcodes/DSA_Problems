#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int slow=0,fast=0;
            do{
                slow=nums[slow];
                fast=nums[nums[fast]];
            }while(fast!=slow);
            slow=0;
            while(true){
                slow=nums[slow];
                fast=nums[fast];
                if(slow==fast){
                    return slow;
                }
            }
            return -1;
        }
    };