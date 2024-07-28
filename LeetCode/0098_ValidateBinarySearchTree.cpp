#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/validate-binary-search-tree/description/

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
    bool isBST(TreeNode *root, long long minvalue, long long maxvalue)
    {
        // base case
        if (root == NULL)
        {
            return true;
        }
        if (root->val > minvalue && root->val < maxvalue)
        {
            return isBST(root->left, minvalue, root->val) && isBST(root->right, root->val, maxvalue);
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};