#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        priority_queue<int> pq(nums.begin(),nums.end());

        long long ans=0;
        while(k){
            int curr = pq.top();
            pq.pop();
            ans+=curr;
            pq.push((curr+2)/3);
            k--;
        }
        return ans;
    }
};