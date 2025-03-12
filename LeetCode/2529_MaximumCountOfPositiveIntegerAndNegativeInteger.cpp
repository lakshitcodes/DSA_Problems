#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int pos=nums.size(),neg=nums.size();
            int l=0,r=nums.size()-1;
            while(l<=r){
                int mid=l + (r-l)/2;
                if(nums[mid]<0){
                    l=mid+1;
                }
                else{
                    neg=mid;
                    r=mid-1;
                }
            }
            l=0,r=nums.size()-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]<1){
                    l=mid+1;
                }
                else{
                    pos=mid;
                    r=mid-1;
                }
            }
            pos=nums.size()-pos;
            cout<<pos<<" "<<neg<<endl;
            return max(pos,neg);
        }
    };