#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/majority-element/description/

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int count=1;
            int element=nums[0];
            for(int i=1;i<nums.size();i++){
                if(nums[i]==element){
                    count++;
                }
                else{
                    count--;
                }
                if(count<0){
                    element=nums[i];
                    count=1;
                }
            }
            return element;
        }
    };