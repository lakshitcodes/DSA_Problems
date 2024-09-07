#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/linked-list-in-binary-tree/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool match(ListNode *head, TreeNode *root)
    {
        if (head == nullptr)
        {
            return true;
        }
        if (root == nullptr)
        {
            return false;
        }
        if (head->val == root->val)
        {
            return match(head->next, root->left) || match(head->next, root->right);
        }
        return false;
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (head == nullptr)
        {
            return true;
        }
        if (root == nullptr)
        {
            return false;
        }
        if (match(head, root))
        {
            return true;
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};