#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;

    int ans = -1;
    Node *temp = root;
    while (temp != nullptr)
    {
        if (temp->data == input)
        {
            return input;
        }
        if (input < temp->data)
        {
            ans = temp->data;
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return ans;
}