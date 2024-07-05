#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)

    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int first = -1;
        int previous = -1;
        vector<int> ans = {INT_MAX, INT_MIN};
        ListNode *prev = nullptr;
        ListNode *curr = head;
        int i = 1;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (prev != nullptr &&
                ((prev->val > curr->val && curr->val < curr->next->val) ||
                 (prev->val < curr->val && curr->val > curr->next->val)))
            {

                if (first == -1)
                {
                    first = i;
                }

                if (previous != -1)
                {
                    ans[0] = min(ans[0], i - previous);
                }

                previous = i;
            }

            prev = curr;
            curr = curr->next;
            i++;
        }

        // If there was no critical point or only one critical point
        if (first == -1 || previous == first)
        {
            return {-1, -1};
        }

        ans[1] = previous - first;
        return ans;
    }
};
