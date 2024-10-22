#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree

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
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        priority_queue<long long,vector<long long>,greater<>> kLarge;
        queue<TreeNode*> pq;
        pq.push(root);
        while(!pq.empty()){
            int size = pq.size();
            long long sum=0;
            for(int i=0;i<size;i++){
                TreeNode* curr = pq.front();
                pq.pop();
                sum+=curr->val;
                if(curr->left)
                    pq.push(curr->left);
                if(curr->right)
                    pq.push(curr->right);
            }
            kLarge.push(sum);
            if(kLarge.size()>k){
                kLarge.pop();
            }
        }
        return kLarge.size()==k ? kLarge.top() : -1;
    }
};