#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        ListNode *slow = head, *fast = head;
        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }
        if (fast == nullptr)
        {
            return head->next;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        delete (toDelete);
        return head;
    }
};