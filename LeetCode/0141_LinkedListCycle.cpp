#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/linked-list-cycle/description/

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            return false;
        }
        ListNode *fast = head, *slow = head;
        // int count=0;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            // count++;
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                // if(count!=pos)  return false;
                return true;
            }
        }
        return false;
    }
};