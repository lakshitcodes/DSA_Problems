#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
    public:
        class SegmentTree {
        private:
            vector<int> tree;
            int n;
            
            // Function to build the tree
            void buildTree(int ind, int low, int high) {
                if (low == high) {
                    tree[ind] = 0;  // Initialize to 0
                    return;
                }
                int mid = low + (high - low) / 2;
                buildTree(2 * ind + 1, low, mid);
                buildTree(2 * ind + 2, mid + 1, high);
                tree[ind] = 0;
            }
    
            // Function to update the segment tree
            void update(int ind, int low, int high, int idx) {
                if (low == high) {
                    tree[ind] += 1; // Increment the count at this index
                    return;
                }
                int mid = low + (high - low) / 2;
                if (idx <= mid) {
                    update(2 * ind + 1, low, mid, idx);
                } else {
                    update(2 * ind + 2, mid + 1, high, idx);
                }
                tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2]; // Update the parent node
            }
    
            // Function to query the count of elements less than the value
            int query(int ind, int low, int high, int l, int r) {
                if (r < low || l > high) return 0;  // Out of range
                if (l <= low && high <= r) return tree[ind];  // Fully within range
                int mid = low + (high - low) / 2;
                int left = query(2 * ind + 1, low, mid, l, r);
                int right = query(2 * ind + 2, mid + 1, high, l, r);
                return left + right;
            }
    
        public:
            SegmentTree(int n) {
                this->n = n;
                tree.resize(4 * n);
                buildTree(0, 0, n - 1);
            }
    
            // Update a specific index
            void update(int idx) {
                update(0, 0, n - 1, idx);
            }
    
            // Query the count of numbers less than a specific index
            int query(int l, int r) {
                return query(0, 0, n - 1, l, r);
            }
        };
    
        vector<int> countSmaller(vector<int>& nums) {
            // Coordinate compression to deal with large numbers
            vector<int> sortedNums = nums;
            sort(sortedNums.begin(), sortedNums.end());
            unordered_map<int, int> compress;
            int compressedValue = 0;
            for (int num : sortedNums) {
                if (compress.find(num) == compress.end()) {
                    compress[num] = compressedValue++;
                }
            }
    
            // Segment Tree to track the count of numbers
            SegmentTree st(compressedValue);
            vector<int> result(nums.size());
    
            // Traverse the array from right to left and use the Segment Tree
            for (int i = nums.size() - 1; i >= 0; --i) {
                // Query how many numbers are smaller than the current number
                result[i] = st.query(0, compress[nums[i]] - 1);
                // Update the count of the current number in the Segment Tree
                st.update(compress[nums[i]]);
            }
    
            return result;
        }
    };
    