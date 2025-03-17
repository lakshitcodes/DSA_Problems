#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/divide-array-into-equal-pairs/

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            
            unordered_map<int,int> mp;
            for(auto &i : nums){
                mp[i]++;
            }
            for(auto &i : mp){
                if(i.second&1){
                    return false;
                }
            }
            return true;
        }
    };