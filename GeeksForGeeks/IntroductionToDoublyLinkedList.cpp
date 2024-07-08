#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        Node *prev = new Node();
        if (arr.size() == 0)
        {
            return prev;
        }
        Node *curr = new Node(arr[0]);
        Node *ans = curr;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            curr->next = temp;
            temp->prev = curr;
            curr = curr->next;
        }
        return ans;
    }
};