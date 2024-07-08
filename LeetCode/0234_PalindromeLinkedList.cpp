#include <bits/stdc++.h>
using namespace std;

// Question Link :https://leetcode.com/problems/palindrome-linked-list/description/

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
    ListNode *reverseLinkedList(ListNode *root)
    {
        if (root == NULL || root->next == NULL)
        {
            return root;
        }
        ListNode *newHead = reverseLinkedList(root->next);
        ListNode *front = root->next;
        front->next = root;
        root->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode *head)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = reverseLinkedList(slow->next);
        slow = head;
        ListNode *second = newHead;
        while (second != NULL)
        {
            if (second->val != slow->val)
            {
                reverseLinkedList(newHead);
                return false;
            }
            second = second->next;
            slow = slow->next;
        }
        reverseLinkedList(newHead);
        return true;
    }
};