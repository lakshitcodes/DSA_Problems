#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode *root)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        int val = INT_MIN;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            level++;
            int curr = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                curr += node->val;

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            if (curr > val)
            {
                val = curr;
                ans = level;
            }
        }
        return ans;
    }
};