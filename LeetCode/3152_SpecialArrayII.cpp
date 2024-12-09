#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/special-array-ii/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefixChange(n, 0);
        
        // Preprocess to fill the prefixChange array
        for (int i = 1; i < n; ++i) {
            prefixChange[i] = prefixChange[i - 1];
            if (nums[i] % 2 != nums[i - 1] % 2) {
                prefixChange[i]++;
            }
        }
        
        vector<bool> ans;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            if (l == r) {
                ans.push_back(true);  // Single element is trivially special
            } else {
                // If the number of changes in the range [l, r] equals (r - l), it means it alternates correctly
                ans.push_back(prefixChange[r] - prefixChange[l] == r - l);
            }
        }
        return ans;
    }
};