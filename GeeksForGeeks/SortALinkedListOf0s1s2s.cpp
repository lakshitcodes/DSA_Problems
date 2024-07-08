#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

// Node is defined as
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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        Node *zero = new Node(-1);
        Node *one = new Node(-1);
        Node *two = new Node(-1);

        Node *zeroHead = zero, *oneHead = one, *twoHead = two;
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        // Ensure the last nodes of each list point to nullptr
        zero->next = oneHead->next != nullptr ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;

        head = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};