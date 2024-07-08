#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/odd-even-linked-list/description/

//   Definition for singly-linked list.
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return head;
        }
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *temp = even;
        while (odd->next != NULL && odd->next->next != NULL && even->next->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        while (odd->next != NULL && odd->next->next != NULL)
        {
            odd->next = odd->next->next;
            odd = odd->next;
        }
        while (even->next != NULL && even->next->next != NULL)
        {
            even->next = even->next->next;
            even = even->next;
        }
        even->next = NULL;
        odd->next = temp;
        return head;
    }
};