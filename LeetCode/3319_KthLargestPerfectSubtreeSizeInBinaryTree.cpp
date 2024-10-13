#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/

class Solution {
public:
    tuple<bool, int, int> checkPerfect(TreeNode* root, vector<int>& sizes) {
        if (!root) return {true, 0, 0}; 

        auto [leftPerfect, leftSize, leftHeight] = checkPerfect(root->left, sizes);
        auto [rightPerfect, rightSize, rightHeight] = checkPerfect(root->right, sizes);

        if (leftPerfect && rightPerfect && leftHeight == rightHeight) {
            int currentSize = leftSize + rightSize + 1; 
            int currentHeight = leftHeight + 1; 
            sizes.push_back(currentSize);
            return {true, currentSize, currentHeight};
        } else {
            return {false, 0, 0};
        }
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes; 
        checkPerfect(root, sizes); 
        sort(sizes.rbegin(), sizes.rend());

        if (sizes.size() >= k) {
            return sizes[k - 1];
        }
        return -1; 
    }
};
