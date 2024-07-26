#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int solve(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = max(0, solve(root->left, maxi));
        int right = max(0, solve(root->right, maxi));
        int ans = root->val + max(left, right);
        maxi = max(maxi, root->val + left + right);
        return ans;
    }
    int maxPathSum(TreeNode *root)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};