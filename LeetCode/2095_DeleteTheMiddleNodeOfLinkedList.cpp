#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head || !head->next)
        {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (fast->next == NULL)
        {
            ListNode *todelete = slow;
            prev->next = slow->next;
            delete (slow);
            return head;
        }
        ListNode *todelete = slow->next;
        slow->next = slow->next->next;
        delete (todelete);
        return head;
    }
};