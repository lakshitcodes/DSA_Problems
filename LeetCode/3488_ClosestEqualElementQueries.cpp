#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/closest-equal-element-queries/

class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n=nums.size();
            unordered_map<int,vector<int>> idx;
            for(int i=0;i<n;i++){
                idx[nums[i]].push_back(i);
            }
            vector<int> ans;
    
            for(auto &i : queries){
                int index=i;
                int num=nums[index];
    
                if(idx[num].size()==1){
                    ans.push_back(-1);
                    continue;
                }
    
                int minDist=INT_MAX;
    
                int l=0,r=idx[num].size()-1;
                int curr=-1;
                while(l<=r){
                    int mid=l+(r-l)/2;
                    if(idx[num][mid]==index){
                        curr=mid;
                        break;
                    }
                    if(idx[num][mid]>index){
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
    
                if(curr>0){
                    minDist=min(minDist,index-idx[num][curr-1]);
                }
                if(curr<idx[num].size()-1){
                    minDist=min(minDist,idx[num][curr+1]-index);
                }
    
                minDist=min({minDist,index + n - (int)idx[num].back(),idx[num][0] + n - index});
                ans.push_back(minDist);    
            }
            return ans;
            
        }
    };