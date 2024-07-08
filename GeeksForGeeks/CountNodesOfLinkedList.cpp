#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0

/* Link list node */

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to count nodes of a linked list.
    int getCount(struct Node *head)
    {

        int count = 0;
        while (head != nullptr)
        {
            count++;
            head = head->next;
        }
        return count;
    }
};