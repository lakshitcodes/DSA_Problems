#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // Graph Approach
    unordered_map<int, vector<int>> graph;
    void makeGraph(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if (root->right)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        makeGraph(root->left);
        makeGraph(root->right);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        queue<int> q;
        vector<int> ans;
        if (!k)
        {
            ans.push_back(target->val);
            return ans;
        }
        makeGraph(root);
        q.push(target->val);
        unordered_map<int, int> visited;
        visited[target->val] = 1;
        while (!q.empty())
        {
            for (int i = q.size(); i > 0; i--)
            {
                int front = q.front();
                q.pop();
                for (auto i : graph[front])
                {
                    if (visited.find(i) == visited.end())
                    {
                        q.push(i);
                        visited[i] = 1;
                        if (k == 1)
                        {
                            ans.push_back(i);
                        }
                    }
                }
            }
            k--;
            if (!k)
                break;
        }
        return ans;
    }
};