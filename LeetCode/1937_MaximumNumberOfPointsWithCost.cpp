#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-number-of-points-with-cost/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = points.size();
        int n = points[0].size();
        vector<long long> prev(n, 0);

        // Initialize the prev array with the values from the last row
        for (int j = 0; j < n; j++) {
            prev[j] = points[m-1][j];
        }

        for (int i = m - 2; i >= 0; i--) {
            vector<long long> left(n, 0), right(n, 0), curr(n, 0);

            // Fill left array
            left[0] = prev[0];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j - 1] - 1, prev[j]);
            }

            // Fill right array
            right[n - 1] = prev[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, prev[j]);
            }

            // Calculate the current row values
            for (int j = 0; j < n; j++) {
                curr[j] = points[i][j] + max(left[j], right[j]);
            }

            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};
