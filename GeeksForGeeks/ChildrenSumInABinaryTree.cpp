#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/children-sum-parent/1

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    int isSumProperty(Node *root)
    {
        if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
        {
            return 1;
        }
        int left = root->left == nullptr ? 0 : root->left->data;
        int right = root->right == nullptr ? 0 : root->right->data;
        if (root->data != left + right)
        {
            return 0;
        }
        int checkLeft = isSumProperty(root->left);
        int checkRight = isSumProperty(root->right);
        return checkLeft && checkRight;
    }
};