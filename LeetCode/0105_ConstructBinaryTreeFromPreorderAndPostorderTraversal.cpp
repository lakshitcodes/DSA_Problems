#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    int find(int element, vector<int> &inorder, int start, int end)
    {
        for (int i = start; i <= end; i++)
        {
            if (element == inorder[i])
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx)
    {
        if (start > end || idx >= inorder.size())
        {
            return NULL;
        }
        int element = preorder[idx++];
        TreeNode *ans = new TreeNode(element);
        if (start == end)
        {
            return ans;
        }
        int div = find(element, inorder, start, end);
        if (div == -1)
        {
            return NULL;
        }
        ans->left = solve(preorder, inorder, start, div - 1, idx);
        ans->right = solve(preorder, inorder, div + 1, end, idx);
        return ans;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int idx = 0;
        TreeNode *ans = solve(preorder, inorder, 0, inorder.size() - 1, idx);
        return ans;
    }
};