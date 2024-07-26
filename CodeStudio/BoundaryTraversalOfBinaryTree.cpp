#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://www.naukri.com/code360/problems/boundary-traversal_790725

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void fillLeafNodes(TreeNode<int> *root, std::vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
    }
    fillLeafNodes(root->left, ans);
    fillLeafNodes(root->right, ans);
}

void fillLeftBoundary(TreeNode<int> *root, std::vector<int> &ans)
{
    TreeNode<int> *curr = root->left;
    while (curr)
    {
        if (curr->left || curr->right)
        {
            ans.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void fillRightBoundary(TreeNode<int> *root, std::vector<int> &ans)
{
    TreeNode<int> *curr = root->right;
    std::vector<int> temp;
    while (curr)
    {
        if (curr->left || curr->right)
        {
            temp.push_back(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    std::vector<int> ans;
    if (!root)
    {
        return ans;
    }
    if (root->left || root->right)
    {
        ans.push_back(root->data);
    }
    fillLeftBoundary(root, ans);
    fillLeafNodes(root, ans);
    fillRightBoundary(root, ans);
    return ans;
}
