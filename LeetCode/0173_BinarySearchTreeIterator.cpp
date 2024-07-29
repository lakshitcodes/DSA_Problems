#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/binary-search-tree-iterator/description/

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
class BSTIterator
{
private:
    vector<int> inorder;
    int currIndex;
    int n;
    void traverse(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
        {
            return;
        }
        traverse(root->left, inorder);
        inorder.push_back(root->val);
        traverse(root->right, inorder);
    }

public:
    BSTIterator(TreeNode *root)
    {
        currIndex = -1;
        traverse(root, inorder);
        n = inorder.size();
    }

    int next()
    {
        currIndex++;
        return inorder[currIndex];
    }

    bool hasNext()
    {
        return n - 1 > currIndex;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */