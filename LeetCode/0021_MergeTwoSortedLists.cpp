#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/merge-two-sorted-lists/

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
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            ListNode* dummy=new ListNode(-1);
            ListNode* ans=dummy;
            while(list1 && list2){
                if(list1->val<=list2->val){
                    dummy->next=list1;
                    list1=list1->next;
                }
                else{
                    dummy->next=list2;
                    list2=list2->next;
                }
                dummy=dummy->next;
            }
            if(list1){
                dummy->next=list1;
            }
            if(list2){
                dummy->next=list2;
            }
            return ans->next;
        }
    };