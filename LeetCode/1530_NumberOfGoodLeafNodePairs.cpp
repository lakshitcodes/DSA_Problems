#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

// Solution Here/**
 * Definition for a binary tree node.
 * struct TreeNode
 {
     *int val;
     *TreeNode *left;
     *TreeNode *right;
     *TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                    *
 };
 * /
     class Solution
 {
 public:
     int ans = 0;
     vector<int> recurs(TreeNode *root, int d)
     {
         if (!root)
             return {};
         if (root->left == NULL && root->right == NULL)
             return {1};
         vector<int> l = recurs(root->left, d);
         vector<int> r = recurs(root->right, d);
         vector<int> neww;
         for (auto &a : l)
         {
             for (auto &b : r)
             {
                 if (a + b <= d)
                     ans++;
             }
             a++;
             if (a < d)
                 neww.push_back(a);
         }
         for (auto &b : r)
         {
             b++;
             if (b < d)
                 neww.push_back(b);
         }
         return neww;
     }
     int countPairs(TreeNode *root, int distance)
     {
         recurs(root, distance);
         return ans;
     }
 };