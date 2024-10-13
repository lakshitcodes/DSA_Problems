#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/

class Solution {
public:
    int findX(vector<int> &nums,int k,int x,int index){
        map<int,int> freq;
        if(k==x){
            int ans=0;
            for(int i=index;i<index+k;i++){
                ans+=nums[i];
            }
            return ans;
        }
        for(int i=index;i<index+k;i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &i : freq)
        {
            pq.push({i.second,i.first});
        }
        int ans=0;
        for(int i=0;i<x && !pq.empty();i++){
            int frequ = pq.top().first;
            int element = pq.top().second;
            pq.pop();
            ans+=frequ*element;
        }
        return ans;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
            ans.push_back(findX(nums,k,x,i));
        }
        return ans;
    }
};