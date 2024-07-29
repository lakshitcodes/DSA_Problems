#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/largest-bst/1

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int a, int b, int c)
    {
        maxNode = a;
        minNode = b;
        maxSize = c;
    }
};
class Solution
{
    NodeValue helper(Node *root)
    {
        if (root == NULL)
        {
            return NodeValue(INT_MIN, INT_MAX, 0);
        }
        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.maxNode < root->data && right.minNode > root->data)
        {
            return NodeValue(max(root->data, right.maxNode), min(root->data, left.minNode), 1 + right.maxSize + left.maxSize);
        }
        else
        {
            return NodeValue(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
        }
    }

public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        return helper(root).maxSize;
    }
};