#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1336160095/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (root == p || root == q)
        {
            return root;
        }
        if (root == nullptr)
        {
            return root;
        }
        if (root->val > p->val && root->val < q->val)
        {
            return root;
        }
        if (root->val > q->val && root->val < p->val)
        {
            return root;
        }
        if (root->val > q->val && root->val > p->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (root->val < q->val && root->val < p->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return nullptr;
    }
};