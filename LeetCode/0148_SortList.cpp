#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sort-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(0);
        ListNode *curr = ans;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1)
        {
            curr->next = l1;
        }
        else
        {
            curr->next = l2;
        }
        return ans->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;

        return merge(sortList(head), sortList(fast));
    }
};