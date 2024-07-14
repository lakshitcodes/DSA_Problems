#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/

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
    ListNode *solve(ListNode *head, unordered_set<int> &store)
    {
        if (head == NULL)
        {
            return nullptr;
        }
        if (store.find(head->val) != store.end())
        {
            return solve(head->next, store);
        }
        head->next = solve(head->next, store);
        return head;
    }
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<int> store;
        for (auto &i : nums)
        {
            store.insert(i);
        }
        return solve(head, store);
    }
};