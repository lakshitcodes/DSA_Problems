#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }

        // Finding tail and length of LL
        int len = 1;
        ListNode *tail = head;

        while (tail->next != NULL)
        {
            tail = tail->next;
            len++;
        }

        // Finding new value of K
        if (k > len)
        {
            k = k % len;
            if (k == 0)
            {
                return head;
            }
        }
        if (k <= len)
        {
            k = len - k;
            if (k == 0)
            {
                return head;
            }
        }

        // Finding Curr node
        int count = 1;
        ListNode *curr = head;
        while (count < k && curr != NULL)
        {
            curr = curr->next;
            count++;
        }

        // pointing curr node to NULL and tail node to head
        ListNode *temp = curr->next; // our new head and it is kth node from end
        curr->next = NULL;
        tail->next = head;
        return temp; // returning temp as it is our new head
    }
};