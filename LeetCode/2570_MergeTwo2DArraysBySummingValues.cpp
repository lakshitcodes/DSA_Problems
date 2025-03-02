#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            map<int,int> mp;
            for(auto &i : nums1){
                mp[i[0]]=i[1];
            }
            for(auto &i : nums2){
                mp[i[0]]+=i[1];
            }
            vector<vector<int>> ans;
            for(auto &i : mp){
                ans.push_back({i.first,i.second});
            }
            return ans;
        }
    };