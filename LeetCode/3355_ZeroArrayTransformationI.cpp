#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/zero-array-transformation-i/

class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            int n=nums.size();
            vector<int> diff(n+1,0);
            for(auto &i : queries){
                diff[i[0]]+=1;
                diff[i[1]+1]-=1;
            }
            nums[0]-=diff[0];
            cout<<nums[0]<<" ";
            for(int i=1;i<n;i++){
                diff[i]+=diff[i-1];
                nums[i]-=diff[i];
                cout<<nums[i]<<" ";
            }
            for(auto &i : nums){
                if(i>0){
                    return false;
                }
            }
            return true;
        }
    };