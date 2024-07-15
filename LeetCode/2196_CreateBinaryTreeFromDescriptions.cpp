#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/create-binary-tree-from-descriptions/description/**
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                  *
};

class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> st;
        TreeNode *root = nullptr;
        unordered_set<int> children;
        for (auto &q : descriptions)
        {
            TreeNode *parent, *child;
            if (st.find(q[0]) != st.end())
            {
                parent = st[q[0]];
            }
            else
            {
                parent = new TreeNode(q[0]);
                st[q[0]] = parent;
            }
            if (st.find(q[1]) != st.end())
            {
                child = st[q[1]];
            }
            else
            {
                child = new TreeNode(q[1]);
                st[q[1]] = child;
            }
            children.insert(q[1]);
            if (q[2])
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        for (auto &q : descriptions)
        {
            if (children.find(q[0]) == children.end())
            {
                return st[q[0]];
            }
        }
        return root;
    }
};
