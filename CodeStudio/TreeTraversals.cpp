#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.naukri.com/code360/problems/tree-traversal_981269

//   Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void postOrder(vector<int> &ans, TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(ans, root->left);
    postOrder(ans, root->right);
    ans.push_back(root->data);
}
void preOrder(vector<int> &ans, TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    ans.push_back(root->data);
    preOrder(ans, root->left);
    preOrder(ans, root->right);
}
void inOrder(vector<int> &ans, TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(ans, root->left);
    ans.push_back(root->data);
    inOrder(ans, root->right);
}
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<int> post, pre, ino;
    postOrder(post, root);
    preOrder(pre, root);
    inOrder(ino, root);
    return {ino, pre, post};
}