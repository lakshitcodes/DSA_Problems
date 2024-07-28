#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1336148217/

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
    void fillInorder(TreeNode *root, vector<int> &inorder, int k)
    {
        if (inorder.size() == k)
        {
            return;
        }
        if (root == nullptr)
        {
            return;
        }
        fillInorder(root->left, inorder, k);
        inorder.push_back(root->val);
        fillInorder(root->right, inorder, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> inorder;
        fillInorder(root, inorder, k);
        return inorder[k - 1];
    }
};