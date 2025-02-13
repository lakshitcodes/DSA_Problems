#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            priority_queue<long long,vector<long long>,greater<>> pq;
            for(auto &i : nums){
                pq.push(i);
            }
            int count=0;
            while(pq.size()>1 && pq.top()<k){
                long long a=pq.top();
                pq.pop();
                long long b=pq.top();
                pq.pop();
                pq.push(min(a,b)*2 + max(a,b));
                count++;
            }
            return count;
        }
    };