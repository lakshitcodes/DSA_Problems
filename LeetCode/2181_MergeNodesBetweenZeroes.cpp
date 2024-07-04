#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/merge-nodes-in-between-zeros/

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        ListNode *temp = head->next;
        ListNode *prev = head;

        while (temp != nullptr)
        {
            if (temp->val == 0)
            {
                if (temp->next != nullptr)
                {
                    prev->next = temp;
                    prev = temp;
                }
                temp = temp->next;
            }
            else
            {
                prev->val += temp->val;
                prev->next = temp->next;
                temp = temp->next;
            }
        }

        prev->next = nullptr;

        return head;
    }
};
