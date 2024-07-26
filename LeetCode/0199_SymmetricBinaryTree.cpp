#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/symmetric-tree/description/

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
    bool solve(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        if (!root1 || !root2)
        {
            return false;
        }
        bool flag = root1->val == root2->val;
        if (!flag)
        {
            return false;
        }
        bool left = solve(root1->left, root2->right);
        bool right = solve(root1->right, root2->left);
        return left && right;
    }
    bool isSymmetric(TreeNode *root)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (!root)
            return true;
        return solve(root->left, root->right);
    }
};