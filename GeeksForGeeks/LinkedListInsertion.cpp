#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    // Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x)
    {
        Node *ans = new Node(x);
        if (head != nullptr)
            ans->next = head;
        return ans;
    }

    // Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)
    {
        if (head == NULL)
        {
            Node *ans = new Node(x);
            return ans;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *ans = new Node(x);
        temp->next = ans;
        return head;
    }
};