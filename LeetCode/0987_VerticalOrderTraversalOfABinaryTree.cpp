#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode *frontElement = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].insert(frontElement->val);
            if (frontElement->left)
            {
                q.push(make_pair(frontElement->left, make_pair(hd - 1, lvl + 1)));
            }
            if (frontElement->right)
            {
                q.push(make_pair(frontElement->right, make_pair(hd + 1, lvl + 1)));
            }
        }
        for (auto i : nodes)
        {
            vector<int> temp;
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};