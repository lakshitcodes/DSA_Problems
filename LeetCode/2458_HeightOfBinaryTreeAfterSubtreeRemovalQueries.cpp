#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/height-of-a-binary-tree-after-deletion-of-the-nodes-with-values-in-a-given-range/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> depth, levelArr, max1, max2;
    // depth stores the height of the subtree from that node
    // max1 stores the maximum height from a level
    // max2 stores the second maximum height from a level
    // levelArr stores the level of the current node
    int findHeights(TreeNode* root, int level) {
        if (root == nullptr) {
            return 0;
        }
        // Setting the level of the current node
        levelArr[root->val] = level;
        // Recursively calculating the maximum height of the subtree
        depth[root->val] = 1 + max(findHeights(root->left, level + 1),
                                   findHeights(root->right, level + 1));

        // Setting the maximum and second maximum heigths at each level
        if (max1[level] < depth[root->val]) {
            max2[level] = max1[level];
            max1[level] = depth[root->val];
        } else if (max2[level] < depth[root->val]) {
            max2[level] = depth[root->val];
        }

        return depth[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        depth.resize(100001, 0);
        levelArr.resize(100001, 0);
        max1.resize(100001, 0);
        max2.resize(100001, 0);

        findHeights(root, 0);

        vector<int> ans;
        for (auto q : queries) {
            // Finding the level at which the current node is present
            int level = levelArr[q];
            //    If the node being removed contributes to the maximum height ,
            //    then give the second maximum height to that query
            // Also we are adding level-1 because max1[level] gives the max
            // depth from current level
            int temp = (max1[level] == depth[q] ? max2[level] : max1[level]) +
                       level - 1;
            ans.push_back(temp);
        }
        return ans;
    }
};