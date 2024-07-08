#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

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
    Node *reverseDLL(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            current->prev = next;

            prev = current;
            current = next;
        }

        return prev;
    }
};