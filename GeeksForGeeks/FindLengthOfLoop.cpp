#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/find-length-of-loop/1

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

// Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    unordered_map<Node *, int> indexes;
    int i = 1;
    Node *temp = head;
    while (head->next != nullptr)
    {
        indexes[head] = i;
        if (indexes.find(head->next) != indexes.end())
        {
            return i - indexes[head->next] + 1;
        }
        i++;
        head = head->next;
    }
    return 0;
}