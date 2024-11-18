#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/


// Time Complexity : O(nlogn)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        int ans = INT_MAX;
        long long currSum=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum>=k){
                ans=min(ans,i+1);
            }
            // Find the minimum window ending at index i
            while(!pq.empty() && currSum-pq.top().first>=k){
                long long sum = pq.top().first;
                int ind = pq.top().second;
                pq.pop();
                ans = min(ans,i-ind);
            }

            pq.push({currSum,i});
        }
        return ans!=INT_MAX ? ans : -1;
    }
};

// Time Complexity : O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        int ans = INT_MAX;
        long long currSum=0;
        deque<pair<long long,int>> pq;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum>=k){
                ans=min(ans,i+1);
            }
            
            //Finding the minimum valid window ending at index i
            while(!pq.empty() && currSum-pq.front().first>=k){
                auto [sum,index] = pq.front();
                pq.pop_front();
                ans=min(ans,i-index);
            }

            //Pushing the currSum in the monotonic deque
            while(!pq.empty() && pq.back().first>currSum){
                pq.pop_back();
            }
            pq.push_back({currSum,i});
        }


        return ans!=INT_MAX ? ans : -1;
    }
};