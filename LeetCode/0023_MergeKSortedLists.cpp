#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    struct Comparator
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val; // This creates a min-heap
        }
    };

    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        std::priority_queue<ListNode *, std::vector<ListNode *>, Comparator> pq;

        // Push the first node of each list into the priority queue
        for (ListNode *list : lists)
        {
            if (list != nullptr)
            {
                pq.push(list);
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;

        while (!pq.empty())
        {
            ListNode *top = pq.top();
            pq.pop();
            current->next = top;
            current = current->next;

            if (top->next != nullptr)
            {
                pq.push(top->next);
            }
        }

        return dummy->next;
    }
};
