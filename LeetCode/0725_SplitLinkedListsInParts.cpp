#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            n++;
        }
        vector<ListNode *> ans(k, nullptr);
        ;
        vector<int> num(k, n / k);
        for (int i = 0; i < n % k; i++)
        {
            num[i]++;
        }
        temp = head;
        for (int i = 0; i < k; i++)
        {
            if (num[i])
            {
                ans[i] = temp;
                for (int j = 1; j < num[i]; j++)
                {
                    temp = temp->next;
                }
                ListNode *curr = temp->next;
                temp->next = nullptr;
                temp = curr;
            }
        }
        return ans;
    }
};