#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/trapping-rain-water/

class Solution {
    public:
        int trap(vector<int>& height) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n = height.size();
            if (n == 0) return 0;
    
            vector<int> left(n), right(n);
            left[0] = height[0];
            for (int i = 1; i < n; i++) {
                left[i] = max(left[i - 1], height[i]);
            }
    
            right[n - 1] = height[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                right[i] = max(right[i + 1], height[i]);
            }
    
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += min(left[i], right[i]) - height[i];
            }
    
            return ans;
        }
    };