#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
               
        unordered_map<string, int> patFreq;
        
        for (const auto& row : mat) {
            string pattern;
            if (row[0] == 0) {
                for (int bit : row) pattern += to_string(bit);
            } else {
                for (int bit : row) pattern += to_string(bit ^ 1);
            }
            patFreq[pattern]++;
        }
        
        int maxFreq = 0;
        for (const auto& pair : patFreq) {
            maxFreq = max(maxFreq, pair.second);
        }
        return maxFreq;
    }
};