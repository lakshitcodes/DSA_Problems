#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool findStart(TreeNode *root, int startValue, string &toStart)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->val == startValue)
        {
            return true;
        }
        bool left = findStart(root->left, startValue, toStart);
        bool right = findStart(root->right, startValue, toStart);
        if (left)
        {
            toStart += 'L';
            return true;
        }
        if (right)
        {
            toStart += 'R';
            return true;
        }
        return false;
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        string toStart = "";
        findStart(root, startValue, toStart);
        string toDest = "";
        findStart(root, destValue, toDest);
        reverse(toStart.begin(), toStart.end());
        reverse(toDest.begin(), toDest.end());
        int i = 0;
        while (i < toStart.size() && i < toDest.size() && toDest[i] == toStart[i])
        {
            i++;
        }
        toStart = string(toStart.length() - i, 'U');
        toDest = toDest.substr(i);
        return toStart + toDest;
    }
};