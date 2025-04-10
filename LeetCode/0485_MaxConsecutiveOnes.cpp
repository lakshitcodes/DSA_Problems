#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/max-consecutive-ones/

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int maxi=0;
            int curr=0;
            for(auto &i : nums){
                if(i==1){
                    curr++;
                }
                else{
                    maxi=max(maxi,curr);
                    curr=0;
                }
            }
            return max(maxi,curr);
        }
    };