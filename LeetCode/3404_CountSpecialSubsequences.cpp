#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-special-subsequences/

class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        unordered_map<double, long long> freq;
        long long ans = 0;
        for(int r = 4; r < nums.size(); ++r){
            for(int p = 0, q = r - 2; p < q-1; ++p) freq[(double)nums[p]/(double)nums[q]]++;
            for(int s = r + 2; s < nums.size(); ++s) ans += freq[(double)nums[s]/(double)nums[r]];
        }
        return ans;
    }
};