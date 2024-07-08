#include <bits/stdc++.h>
using namespace std;

// Question Link :https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

struct Node
{
    int data;
    Node *next;
    Node *prev;
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
    Node *removeDuplicates(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Node *current = head;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->data == current->next->data)
            {
                Node *toDelete = current->next;
                current->next = toDelete->next;
                if (toDelete->next != nullptr)
                {
                    toDelete->next->prev = current;
                }
                delete toDelete;
            }
            else
            {
                current = current->next;
            }
        }

        return head;
    }
};