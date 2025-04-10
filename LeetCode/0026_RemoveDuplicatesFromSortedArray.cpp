#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int unique=1;
            int i=0;
            for(int j=1;j<nums.size();j++){
                while(j<nums.size() && nums[j]==nums[i]){
                    j++;
                }
                if(j<nums.size() && nums[i]!=nums[j]){
                    i++;
                    nums[i]=nums[j];
                    unique++;
                }
            }
            return unique;
        }
    };