#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

// Node of the doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

// Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    int count = 0;
    Node *curr = head;
    while (curr->next != nullptr)
    {
        if (count == pos)
        {
            temp->prev = curr;
            temp->next = curr->next;
            curr->next->prev = temp;
            curr->next = temp;
            return;
        }
        count++;
        curr = curr->next;
    }
    if (curr->next == NULL && count == pos)
    {
        curr->next = temp;
        temp->prev = curr;
    }
}