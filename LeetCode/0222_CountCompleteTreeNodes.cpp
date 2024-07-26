#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/count-complete-tree-nodes/description/

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
    int countNodes(TreeNode *root)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (!root)
        {
            return 0;
        }
        int count = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *element = q.front();
            q.pop();
            count++;
            if (element->left)
            {
                q.push(element->left);
            }
            if (element->right)
            {
                q.push(element->right);
            }
        }
        return count;
    }
};