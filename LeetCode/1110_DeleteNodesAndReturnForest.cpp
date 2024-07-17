#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/delete-nodes-and-return-forest/description

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    TreeNode *solve(TreeNode *root, unordered_set<int> &toDelete,
                    vector<TreeNode *> &ans)
    {
        if (root == nullptr)
        {
            return root;
        }
        root->left = solve(root->left, toDelete, ans);
        root->right = solve(root->right, toDelete, ans);
        if (toDelete.find(root->val) != toDelete.end())
        {
            if (root->left)
            {
                ans.push_back(root->left);
            }
            if (root->right)
            {
                ans.push_back(root->right);
            }
            TreeNode *deleteNode = root;
            delete (deleteNode);
            return nullptr;
        }
        return root;
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<int> toDelete;
        for (auto &i : to_delete)
        {
            toDelete.insert(i);
        }
        vector<TreeNode *> ans;
        if (solve(root, toDelete, ans))
            ans.push_back(root);
        return ans;
    }
};