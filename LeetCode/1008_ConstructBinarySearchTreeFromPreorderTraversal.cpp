#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    TreeNode *buildTree(int start, int end, vector<int> &preorder)
    {
        if (start > end)
        {
            return nullptr;
        }
        if (start == end)
        {
            TreeNode *ans = new TreeNode(preorder[start]);
            return ans;
        }
        int bigIndex = -1;
        for (int i = start; i <= end; i++)
        {
            if (preorder[i] > preorder[start])
            {
                bigIndex = i;
                break;
            }
        }
        TreeNode *ans = new TreeNode(preorder[start]);
        ans->left = buildTree(start + 1, bigIndex == -1 ? end : bigIndex - 1, preorder);
        if (bigIndex != -1)
        {
            ans->right = buildTree(bigIndex, end, preorder);
        }
        return ans;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        return buildTree(0, preorder.size() - 1, preorder);
    }
};