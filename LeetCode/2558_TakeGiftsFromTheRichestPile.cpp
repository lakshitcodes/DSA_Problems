#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/take-gifts-from-the-richest-pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans=accumulate(gifts.begin(),gifts.end(),0LL);
        priority_queue<int> pq(gifts.begin(),gifts.end());
        while(!pq.empty() && k--){
            int ele=pq.top();
            pq.pop();
            int root=sqrt(ele);
            ans-=ele-root;
            pq.push(root);
        }
        return ans;
    }
};