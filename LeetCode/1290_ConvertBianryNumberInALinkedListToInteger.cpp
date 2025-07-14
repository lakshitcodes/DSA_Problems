#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode *head)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string binary = "";
        while (head != nullptr)
        {
            binary += to_string(head->val);
            head = head->next;
        }
        cout << binary;
        int ans = 0;
        int multi = 1;
        for (int i = binary.length() - 1; i >= 0; i--)
        {
            if (binary[i] == '1')
            {
                ans += multi;
            }
            multi *= 2;
        }
        return ans;
    }
};