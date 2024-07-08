#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode *solve(ListNode *head, int k, int n)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL || n < k)
        {
            return head;
        }
        int count = 0;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next;
        while (curr != nullptr && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != nullptr)
        {
            head->next = solve(curr, k, n - k);
        }
        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return solve(head, k, count);
    }
};