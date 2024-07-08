#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/*  Function which returns the  root of
    the flattened linked list. */
Node *merge(Node *l1, Node *l2)
{
    Node *dummyHead = new Node(-1);
    Node *ans = dummyHead;
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            dummyHead->bottom = l1;
            dummyHead = l1;
            l1 = l1->bottom;
        }
        else
        {
            dummyHead->bottom = l2;
            dummyHead = l2;
            l2 = l2->bottom;
        }
    }
    if (l1)
    {
        dummyHead->bottom = l1;
    }
    else
    {
        dummyHead->bottom = l2;
    }
    if (ans->bottom)
    {
        ans->bottom->next = NULL;
    }
    return ans->bottom;
}
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    Node *mergeAhead = flatten(root->next);
    root = merge(root, mergeAhead);
    return root;
}