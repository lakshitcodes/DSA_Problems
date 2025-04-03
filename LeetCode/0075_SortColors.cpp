#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/sort-colors/

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
    
            // The easiest will be to count the occurences of 0,1,2 and then place them accordingly
            // We will be using DNF Sort
    
            int low=0,mid=0,high=nums.size()-1;
            while(mid<=high){
                if(nums[mid]==0){
                    swap(nums[low],nums[mid]);
                    low++;mid++;
                }
                else if(nums[mid]==1){
                    mid++;
                }
                else if(nums[mid]==2){
                    swap(nums[mid],nums[high]);
                    high--;
                }
            }
        }
    };