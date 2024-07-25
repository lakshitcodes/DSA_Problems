#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/binary-tree-representation/1

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);

    class Solution
    {
    public:
        node *buildTree(int index, vector<int> vec)
        {
            if (index >= vec.size())
            {
                return nullptr;
            }
            node *ans = newNode(vec[index]);
            ans->left = buildTree(2 * index + 1, vec);
            ans->right = buildTree(2 * index + 2, vec);
            return ans;
        }
        void create_tree(node *root0, vector<int> &vec)
        {
            root0->left = buildTree(1, vec);
            root0->right = buildTree(2, vec);
            return;
        }
    };