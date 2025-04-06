#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            unordered_set<int> store(nums.begin(),nums.end());
            int ans=0;
            for(auto &i : nums){
                if(store.find(i-1)==store.end()){
                    int len=1;
                    while(store.find(i+len)!=store.end()){
                        store.erase(i+len);
                        len++;
                    }
                    ans=max(ans,len);
                }
            }
            return ans;
        }
    };