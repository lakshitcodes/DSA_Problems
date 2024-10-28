#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/longest-square-streak-in-an-array   

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(),nums.end());
        unordered_map<int,int> prevLength;
        int maxLength = 0;
        for(auto &i : nums){
            int root = sqrt(i);
            if(root*root==i && prevLength.find(root)!=prevLength.end()){
                prevLength[i]=prevLength[root]+1;
                maxLength=max(maxLength,prevLength[i]);
            }
            else{
                prevLength[i]=1;
            }
        }
        return maxLength==0 ? -1 : maxLength;
    }
};
