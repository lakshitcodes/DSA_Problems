#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/copy-list-with-random-pointer/description/

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mapping;
        Node *temp = head;
        Node *newHead = new Node(-1);
        Node *temp2 = newHead;
        while (temp != NULL)
        {
            Node *insert = new Node(temp->val);
            mapping[temp] = insert;
            temp2->next = insert;
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp2 = newHead->next;
        temp = head;
        while (temp != NULL)
        {
            Node *toPut = mapping[temp->random];
            temp2->random = toPut;
            temp2 = temp2->next;
            temp = temp->next;
        }
        return newHead->next;
    }
};