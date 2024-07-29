#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    void traverse(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }
        traverse(root->left, arr);
        arr.push_back(root->val);
        traverse(root->right, arr);
    }
    bool findTarget(TreeNode *root, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> arr;
        traverse(root, arr);
        int i = 0, j = arr.size() - 1;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == k)
            {
                return true;
            }
            if (sum > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};