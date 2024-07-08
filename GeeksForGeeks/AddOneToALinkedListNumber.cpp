#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int findCarry(Node *root)
    {
        if (root == NULL)
        {
            return 1;
        }
        int carry = findCarry(root->next);
        if (carry)
        {
            int val = 1 + root->data;
            carry = val / 10;
            val %= 10;
            root->data = val;
        }
        return carry;
    }
    Node *addOne(Node *head)
    {
        int carry = findCarry(head);
        if (carry)
        {
            Node *newHead = new Node(carry);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};