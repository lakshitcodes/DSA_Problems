#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

//  Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        unordered_set<int> store;
        vector<pair<int, int>> ans;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (store.find(target - temp->data) != store.end())
            {
                ans.push_back({target - temp->data, temp->data});
            }
            else
            {
                store.insert(temp->data);
            }
            temp = temp->next;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};