#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        int maxEle = *max_element(nums.begin(), nums.end());
        int size = maxEle + k + 2;
        vector<int> freq(size, 0);

        for (int num : nums) {
            freq[num]++;
        }

        vector<int> prefix(size, 0);
        prefix[0] = freq[0];
        for (int i = 1; i < size; i++) {
            prefix[i] = prefix[i - 1] + freq[i];
        }

        int result = 0;
        for (int x = 0; x < size; x++) {
            if (freq[x] == 0 && numOperations == 0) {
                continue;
            }

            int left = max(0, x - k);
            int right = min(size - 1, x + k);
            int totalInRange = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
            int canAdjust = totalInRange - freq[x];
            int total = freq[x] + min(numOperations, canAdjust);
            result = max(result, total);
        }

        return result;
    }
};