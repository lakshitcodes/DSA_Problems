#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> store;
        ListNode *temp = headA;
        while (temp != NULL)
        {
            store.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != NULL)
        {
            if (store.find(temp) != store.end())
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};