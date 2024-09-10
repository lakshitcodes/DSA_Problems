#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list

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
    int findGCD(int a, int b)
    {
        if (a < b)
        {
            return findGCD(b, a);
        }
        if (b == 0)
        {
            return a;
        }
        return findGCD(b, a % b);
    }
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *node = head;
        while (node != nullptr && node->next != nullptr)
        {
            int gcd = findGCD(node->val, node->next->val);
            ListNode *toInsert = new ListNode(gcd);
            ListNode *next = node->next;
            node->next = toInsert;
            toInsert->next = next;
            node = next;
        }
        return head;
    }
};