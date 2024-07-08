#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

//  a Node of the doubly linked list
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

class Solution
{
public:
    void deleteAllOccurOfX(struct Node **headRef, int x)
    {
        Node *temp = *headRef;

        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                Node *toDelete = temp;

                // Update head if the node to be deleted is the head
                if (temp == *headRef)
                {
                    *headRef = temp->next;
                    if (*headRef != nullptr)
                    {
                        (*headRef)->prev = nullptr;
                    }
                }
                else
                {
                    Node *nextNode = temp->next;
                    Node *prevNode = temp->prev;

                    if (nextNode)
                    {
                        nextNode->prev = prevNode;
                    }
                    if (prevNode)
                    {
                        prevNode->next = nextNode;
                    }
                }

                temp = temp->next;
                delete toDelete;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};