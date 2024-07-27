#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode
 {
     *int val;
     *TreeNode *left;
     *TreeNode *right;
     *TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                    *
 };
 */

class Solution
{
public:
    void solve(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Morris Traversal

vector<int> getInorder(TreeNode *root)
{
    vector<int> ans;
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->left == nullptr)
        {
            ans.push_back(curr->val);
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = nullptr;
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return ans;
}