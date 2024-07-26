#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        stack<int> st;
        int k = 1;
        vector<int> temp;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front != NULL)
            {
                if (k == 1)
                {
                    temp.push_back(front->val);
                }
                else
                {
                    st.push(front->val);
                }
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }

            if (front == NULL)
            {
                if (k == 1)
                {
                    ans.push_back(temp);
                    temp.clear();
                }
                else
                {
                    while (!st.empty())
                    {
                        temp.push_back(st.top());
                        st.pop();
                    }
                    ans.push_back(temp);
                    temp.clear();
                }
                k *= -1;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};