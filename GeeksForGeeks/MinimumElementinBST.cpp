#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

class Solution
{
public:
    int minValue(Node *root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root->data;
    }
};