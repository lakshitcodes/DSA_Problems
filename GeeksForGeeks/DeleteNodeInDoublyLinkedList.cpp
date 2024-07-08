#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

//  Structure of Node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        Node *temp = head;

        if (x == 1)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return head;
        }

        for (int i = 1; temp != nullptr && i < x; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            return head;
        }

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }

        delete temp;

        return head;
    }
};
