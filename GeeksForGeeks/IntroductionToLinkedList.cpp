#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1

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
    Node *constructLL(vector<int> &arr)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (arr.size() == 0)
        {
            return nullptr;
        }
        Node *head = new Node(arr[0]);
        Node *ans = head;
        int i = 1;
        while (i < arr.size())
        {
            Node *temp = new Node(arr[i]);
            head->next = temp;
            head = head->next;
            i++;
        }
        return ans;
    }
};