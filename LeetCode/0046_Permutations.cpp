#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/permutations/

class Solution {
    public:
        void solve(vector<int> &curr,vector<bool> &visited,vector<int> &nums,vector<vector<int>> &ans){
            if(curr.size()==nums.size()){
                ans.push_back(curr);
                return;
            }
            for(int i=0;i<nums.size();i++){
                if(!visited[i]){
                    visited[i]=true;
                    curr.push_back(nums[i]);
                    solve(curr,visited,nums,ans);
                    curr.pop_back();
                    visited[i]=false;
                }
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n=nums.size();
            vector<int> curr;
            vector<bool> vis(n,false);
            vector<vector<int>> ans;
            solve(curr,vis,nums,ans);
            return ans;
        }
    };