#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/partition-array-according-to-the-given-point/

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<int> left,right;
            for(auto &i : nums){
                if(i<pivot){
                    left.push_back(i);
                }
                if(i>pivot){
                    right.push_back(i);
                }
            }
            int req=nums.size()-left.size()-right.size();
            for(int i=0;i<req;i++){
                left.push_back(pivot);
            }
            left.insert(left.end(),right.begin(),right.end());
            return left;
        }
    };