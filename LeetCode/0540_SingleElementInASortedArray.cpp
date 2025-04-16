#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            int left = 0, right = nums.size() - 1;
            while(left < right){
                int mid = (left + right)/2;
                if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                    left = mid + 1;
                else
                    right = mid;
            }
            
            return nums[left];
        }
    };