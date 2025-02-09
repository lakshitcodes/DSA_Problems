#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-number-of-bad-pairs/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long n=nums.size();
        unordered_map<int,int> diff;
        for(int i=0;i<n;i++){
            diff[nums[i]-i]++;
        }
        long long good=0;
        for(auto &i : diff){
            long long freq = i.second;
            good+=((freq-1)*freq)/2;
        }
        long long total = n*(n-1)/2;
        return total-good;
    }
};