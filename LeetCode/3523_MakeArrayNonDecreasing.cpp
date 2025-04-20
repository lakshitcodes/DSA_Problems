#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/make-array-non-decreasing/

class Solution {
    public:
        int maximumPossibleSize(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<int> ans;
            for(auto &i : nums){
                if(ans.empty() || ans.back()<=i){
                    ans.push_back(i);
                }
            }
            return ans.size();
        }
    };