#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/diameter-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    pair<int, int> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }
        pair<int, int> leftTree = solve(root->left);
        pair<int, int> rightTree = solve(root->right);
        pair<int, int> ans;
        ans.first = max(leftTree.first, max(rightTree.first, leftTree.second + rightTree.second + 1));
        ans.second = 1 + max(rightTree.second, leftTree.second);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        return solve(root).first - 1;
    }
};