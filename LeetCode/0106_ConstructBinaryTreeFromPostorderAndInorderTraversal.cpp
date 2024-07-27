#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
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
    TreeNode *solve(vector<int> &postorder, vector<int> &inorder, int start,
                    int end, int &idx)
    {
        if (start > end || idx < 0)
        {
            return nullptr;
        }
        int element = postorder[idx--];
        TreeNode *ans = new TreeNode(element);
        if (start == end)
        {
            return ans;
        }
        int mid = find(element, inorder, start, end);
        if (mid == -1)
        {
            return nullptr;
        }
        ans->right = solve(postorder, inorder, mid + 1, end, idx);
        ans->left = solve(postorder, inorder, start, mid - 1, idx);

        return ans;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int idx = postorder.size() - 1;
        TreeNode *ans = solve(postorder, inorder, 0, postorder.size() - 1, idx);
        return ans;
    }
};